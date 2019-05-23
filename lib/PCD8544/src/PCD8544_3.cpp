//
// Created by user1 on 23.05.19.
//

#include "PCD8544_3.h"

PCD8544_3::PCD8544_3(void (*reset)(), void (*write)(uint8_t, uint8_t)) {
    this->reset = reset;
    this->write = write;
}

void PCD8544_3::initialize() {
    this->reset();
    this->write(PCD8544_3_C, 0x21);  // LCD Extended Commands.
    this->write(PCD8544_3_C, 0xB1);  // Set LCD Vop (Contrast).
    this->write(PCD8544_3_C, 0x04);  // Set Temp coefficent. //0x04
    this->write(PCD8544_3_C, 0x14);  // LCD bias mode 1:48. //0x13
    this->write(PCD8544_3_C, 0x20);  // LCD Basic Commands
    this->write(PCD8544_3_C, 0x0C);  // LCD in normal mode.
}

void PCD8544_3::clear() {
    this->setXY(0, 0);

    for (uint16_t index = 0; index < (PCD8544_3_X * PCD8544_3_Y / 8); index++) {
        this->write(PCD8544_3_D, 0x00);
    }
}

void PCD8544_3::setXY(uint8_t x, uint8_t y) {
    this->write(PCD8544_3_C, 0x80 | x);  // Column.
    this->write(PCD8544_3_C, 0x40 | y);  // Row.
}

void PCD8544_3::character(char character) {
    this->write(PCD8544_3_D, 0x00);

    for (int index = 0; index < 5; index++) {
        this->write(PCD8544_3_D, PCD8544_3_Font[character - 0x20][index]);
    }

    this->write(PCD8544_3_D, 0x00);
}

void PCD8544_3::string(const char *characters) {
    while (*characters) {
        this->character(*characters++);
    }
}
