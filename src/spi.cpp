#include <stm32f1xx.h>

void SPI1_Init()
{
    // Enable clock SPI1 & GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN | RCC_APB2ENR_IOPAEN;

    // Reset GPIO config
    GPIOA->CRL &= ~(GPIO_CRL_CNF5 | GPIO_CRL_MODE5);
    GPIOA->CRL &= ~(GPIO_CRL_CNF6 | GPIO_CRL_MODE6);
    GPIOA->CRL &= ~(GPIO_CRL_CNF7 | GPIO_CRL_MODE7);

    // PA5 - SCK: MODE5 = 0x03 (0b11); CNF5 = 0x02 (0b10)
    GPIOA->CRL |= GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0 | GPIO_CRL_CNF5_1;

    // PA6 - MISO: MODE6 = 0x00 (0b00); CNF6 = 0x01 (0b01)
    GPIOA->CRL |= GPIO_CRL_CNF6_1;

    // PA7 - MOSI: MODE7 = 0x03 (0b11); CNF7 = 0x02 (0b10)
    GPIOA->CRL |= GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0 | GPIO_CRL_CNF7_1;

    // Configure SPI1
    SPI1->CR1 &= ~SPI_CR1_DFF;      // Frame == 8bit
    SPI1->CR1 &= ~SPI_CR1_LSBFIRST; // MSB first
    SPI1->CR1 |= SPI_CR1_SSM;       // Program control SS
    SPI1->CR1 |= SPI_CR1_SSI;       // SS set high
    SPI1->CR1 |= SPI_CR1_BR_2;      // Speed == F_PCLK/32 (0b100)
    SPI1->CR1 |= SPI_CR1_MSTR;      // Master
    SPI1->CR1 &= ~SPI_CR1_CPOL;     // Polarity: 0 TODO description
    SPI1->CR1 &= ~SPI_CR1_CPHA;     // Phase: 0 TODO description

    // Enable SPI1
    SPI1->CR1 |= SPI_CR1_SPE;
}
