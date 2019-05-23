#include "PCD8544_2.h"

void PCD8544_initialize()
{
//    pinMode(PIN_SCE, OUTPUT);
//    pinMode(PIN_RESET, OUTPUT);
//    pinMode(PIN_DC, OUTPUT);
//    pinMode(PIN_SDIN, OUTPUT);
//    pinMode(PIN_SCLK, OUTPUT);
//    digitalWrite(PIN_RESET, LOW);
//    digitalWrite(PIN_RESET, HIGH);

    PCD8544_write(PCD8544_C, 0x21);  // LCD Extended Commands.
    PCD8544_write(PCD8544_C, 0xB1);  // Set LCD Vop (Contrast).
    PCD8544_write(PCD8544_C, 0x04);  // Set Temp coefficent. //0x04
    PCD8544_write(PCD8544_C, 0x14);  // LCD bias mode 1:48. //0x13
    PCD8544_write(PCD8544_C, 0x20);  // LCD Basic Commands
    PCD8544_write(PCD8544_C, 0x0C);  // LCD in normal mode.

//    LcdWrite( LCD_CMD, 0x21 );  // LCD Extended Commands.
//    LcdWrite( LCD_CMD, 0xBf );  // Set LCD Vop (Contrast). //B1
//    LcdWrite( LCD_CMD, 0x04 );  // Set Temp coefficent. //0x04
//    LcdWrite( LCD_CMD, 0x14 );  // LCD bias mode 1:48. //0x13
//    LcdWrite( LCD_CMD, 0x0C );  // LCD in normal mode. 0x0d for inverse
//    LcdWrite(LCD_C, 0x20);
//    LcdWrite(LCD_C, 0x0C);
}

void PCD8544_write(PCD8544_t *lcd, uint8_t mode, uint8_t data)
{
    lcd->write(mode, data);
}

void PCD8544_write(uint8_t mode, uint8_t data)
{
//    digitalWrite(PIN_DC, dc);
//    digitalWrite(PIN_SCE, LOW);
//    shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
//    digitalWrite(PIN_SCE, HIGH);
}

void PCD8544_setXY(uint8_t x, uint8_t y)
{
    PCD8544_write(PCD8544_C, 0x80 | x);  // Column.
    PCD8544_write(PCD8544_C, 0x40 | y);  // Row.
}

void PCD8544_clear()
{
    PCD8544_setXY(0, 0);

    for (uint16_t index = 0; index < (PCD8544_X * PCD8544_Y / 8); index++) {
        PCD8544_write(PCD8544_D, 0x00);
    }
}

void PCD8544_character(char character)
{
    PCD8544_write(PCD8544_D, 0x00);

    for (int index = 0; index < 5; index++) {
        PCD8544_write(PCD8544_D, PCD8544_Font[character - 0x20][index]);
    }

    PCD8544_write(PCD8544_D, 0x00);
}

void PCD8544_string(const char *characters)
{
    while (*characters) {
        PCD8544_character(*characters++);
    }
}