#define F_CPU_INTERNAL 1000000U

#include "stm32f1xx.h"
#include "PCD8544.h"

void delay__us(uint32_t us)
{
    uint32_t ticks = (uint32_t) ((float) us * ((float) SystemCoreClock / (float) 1000000));

    for (uint32_t i = 0; i < ticks; i++) {
        asm("nop");
    }
}

#define    DWT_CYCCNT    *(volatile unsigned long *)0xE0001004
#define    DWT_CONTROL   *(volatile unsigned long *)0xE0001000
#define    SCB_DEMCR     *(volatile unsigned long *)0xE000EDFC


void DWT_Init(void)
{
    //разрешаем использовать счётчик
    SCB_DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    //обнуляем значение счётного регистра
    DWT->CYCCNT = 0;

    //запускаем счётчик
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

static __inline uint32_t delta(uint32_t t0, uint32_t t1)
{
    return (t1 - t0);
}

void delay_us(uint32_t us)
{
    uint32_t t0 =  DWT->CYCCNT;
    uint32_t us_count_tic =  us * (SystemCoreClock/1000000);

    while (delta(t0, DWT->CYCCNT) < us_count_tic) ;
}

void ClockInit()
{
    uint32_t counter;

    // Enable external oscillator
    RCC->CR |= RCC_CR_HSEON;

    // Check enabled
    for (counter = 0; ; counter++) {
        if (RCC->CR & RCC_CR_HSERDY) {
            break;
        }

        if (counter > 0x1000) {
            // Fallback to internal oscillator
            RCC->CR &= ~RCC_CR_HSEON;
            return;
        }
    }

    // Select PLL from HSE source & multiply by 9
    RCC->CFGR |= RCC_CFGR_PLLMULL_2|RCC_CFGR_PLLMULL_1|RCC_CFGR_PLLMULL_0;
    RCC->CFGR |= RCC_CFGR_PLLSRC;

    RCC->CR |= RCC_CR_PLLON;

    // Check enabled
    for (counter = 0; ; counter++) {
        if (RCC->CR & RCC_CR_PLLRDY) {
            break;
        }

        if (counter > 0x1000) {
            // Fallback to internal oscillator
            RCC->CR &= ~RCC_CR_HSEON;
            RCC->CR &= ~RCC_CR_PLLON;
            return;
        }
    }

    // Select Flash waiting to 2 cycles for 48 MHz < SYSCLK <= 72 MHz
    FLASH->ACR |= FLASH_ACR_LATENCY_1;

    RCC->CFGR |= RCC_CFGR_PPRE1; //Divider for APB1 2

    // Use pll as system clock
    RCC->CFGR |= RCC_CFGR_SW_1;

    // Wait for clock source changed
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1);
}

void ClockInit2()
{
    RCC->CR |= RCC_CR_HSEON; // Запустить HSE

    while ((RCC->CR & RCC_CR_HSERDY) == 0); // Ожидание готовности HSE

    RCC->CFGR |= RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE2_DIV1 | RCC_CFGR_PPRE1_DIV1; // HCLK = SYSCLK ;  PCLK2 = HCLK ; PCLK1 = HCLK
    RCC->CFGR &= ~((RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL)); // Предочистка
    RCC->CFGR |= RCC_CFGR_PLLSRC; // Тактировать PLL от HSE (8 MHz)
    RCC->CFGR |= RCC_CFGR_PLLMULL9; // Умножать частоту на 9 (8*9=72 MHz)
    RCC->CR |= RCC_CR_PLLON; // Запустить PLL

    while ((RCC->CR & RCC_CR_PLLRDY) == 0); // Ожидание готовности PLL

    FLASH->ACR |= FLASH_ACR_PRFTBE; // Включить Prefetch Buffer
    FLASH->ACR &= ~(FLASH_ACR_LATENCY); // Предочистка
    FLASH->ACR |= FLASH_ACR_LATENCY_2; // Пропускать 2 такта

    RCC->CFGR &= ~RCC_CFGR_SW; // Очистить биты SW0, SW1
    RCC->CFGR |= RCC_CFGR_SW_PLL; // Тактирование с выхода PLL

    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1); // Ожидание переключения на PLL
}

//TODO configure SPI2 or SPI1
// PB11 Data/Command selection (DC)
// PB12 AFO Push-Pull @ 50 МГц (CS)
// PB13 AFO Push-Pull @ 50 МГц (SCK)
// PB14 AFI Pull-up (MISO)
// PB15 AFO Push-Pull @ 50 МГц (MOSI)
PCD8544 pcd8544_1 = PCD8544(
        [](uint8_t mode){ GPIOB->BSRR = mode ? GPIO_BSRR_BS11 : GPIO_BSRR_BR11; },
        [](uint8_t data){ SPI2->DR = data; }
);

int main()
{
    ClockInit2();
    SystemCoreClockUpdate();
    DWT_Init();

    // Enable gpioc clocking
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // Rest mode
    GPIOC->CRH &= ~GPIO_CRH_MODE13;

    // Reset function
    GPIOC->CRH &= ~GPIO_CRH_CNF13;

    // Set mode 10
    GPIOC->CRH |= GPIO_CRH_MODE13_1;

    pcd8544_1.initialize();

    while (true) {
        GPIOC->BSRR = GPIO_BSRR_BS13;

        delay_us(500000);

        GPIOC->BSRR = GPIO_BSRR_BR13;

        delay_us(500000);
    }
}