#include <stdint.h>

#include "PCD8544_2.h"

int main()
{
    PCD8544_t lcd = {
        .reset = [](){},                           //TODO <-- implement reset pin manipulation
        .write = [](uint8_t mode, uint8_t data){}, //TODO <-- implement communicate with display
    };

    PCD8544_initialize(&lcd);
    PCD8544_clear(&lcd);
    PCD8544_string(&lcd, "HELLO");
}
