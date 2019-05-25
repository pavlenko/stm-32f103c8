#include "PCF8812.h"

void PCF8812_initialize(PCF8812_t *lcd)
{
    lcd->reset();

    lcd->write(PCF8812_C, 0x21);  // Function set: extended instruction set    --21
    lcd->write(PCF8812_C, 0x14);  // Bias System                               --14
    lcd->write(PCF8812_C, 0x0A);  // HV-gen stages                             --0A
    lcd->write(PCF8812_C, 0x05);  // Temperature Control                       --05
    lcd->write(PCF8812_C, 0xCC);  // Contrast: 204                             --CC
    lcd->write(PCF8812_C, 0x20);  // Function set: standard instruction set    --20
    lcd->write(PCF8812_C, 0x11);  // VLCD programming range: high              --11
    lcd->write(PCF8812_C, 0x0C);  // Display control: normal (inverted = 0x0D) --0C
}

void PCF8812_setXY(PCF8812_t *lcd, uint8_t x, uint8_t y)
{
    lcd->write(PCF8812_C, 0x80 | x);  // Column.
    lcd->write(PCF8812_C, 0x40 | y);  // Row.
}

void PCF8812_clear(PCF8812_t *lcd)
{
    PCF8812_setXY(lcd, 0, 0);

    for (uint16_t index = 0; index < (PCF8812_X * PCF8812_Y / 8); index++) {
        lcd->write(PCF8812_D, 0x00);
    }
}

void PCF8812_character(PCF8812_t *lcd, char character)
{
    lcd->write(PCF8812_D, 0x00);

    for (int index = 0; index < 5; index++) {
        lcd->write(PCF8812_D, PCF8812_Font[character - 0x20][index]);
    }

    lcd->write(PCF8812_D, 0x00);
}

void PCF8812_string(PCF8812_t *lcd, const char *characters)
{
    while (*characters) {
        PCF8812_character(lcd, *characters++);
    }
}