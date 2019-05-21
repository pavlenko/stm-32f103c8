#include <stm32f1xx.h>

class SPIn_Class {
private:
    SPI_TypeDef *spi;
public:
    void send(uint16_t data)
    {
        while (!(spi->SR & SPI_SR_TXE));
        spi->DR = data;
    }

    uint16_t read()
    {
        spi->DR = 0;
        while (!(spi->SR & SPI_SR_RXNE));
        return spi->DR;
    }
};