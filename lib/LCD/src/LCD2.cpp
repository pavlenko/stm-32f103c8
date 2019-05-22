#include "LCD2.h"

void LCD_clear(LCD_handle_t handle)
{
    for (uint16_t i = 0; i < sizeof(handle.buffer); i++) {
        *(handle.buffer + i) = 0x00u;
    }
}

void LCD_string(LCD_handle_t handle, const char *string, uint8_t x, uint8_t y, bool wrap)
{
    uint16_t shift = (y % 8u);
    uint16_t index;

    while (*string != 0x00u) {
        index = (uint16_t) (x + (y / 8u) * handle.width);

        for (uint8_t i = 0; i < 5; i++) {
            uint8_t column = LCDFont5x7[(*string) - 0x20u][i];

            if (index + i < sizeof(handle.buffer)) {
                if (shift == 0) {
                    // Single row render
                    *(handle.buffer + index + i) = column;
                } else {
                    // First row render
                    *(handle.buffer + index + i) = column << shift;

                    if (index + i + handle.width < sizeof(handle.buffer)) {
                        // Second row render
                        *(handle.buffer + index + i + handle.width) = column >> (8u - shift);
                    }
                }
            }
        }

        // Go to next char
        string++;

        x += 5;

        index = (x + (y / 8) * handle.width);
        if (index < sizeof(handle.buffer)) {
            if (shift == 0) {
                // Single row render
                *(handle.buffer + index) = 0x00;
            } else {
                // First row render
                *(handle.buffer + index) = 0x00;

                if (index + handle.width < sizeof(handle.buffer)) {
                    // Second row render
                    *(handle.buffer + index + handle.width) = 0x00;
                }
            }
        }

        x++;

        if (wrap && x > (handle.width - 5)) {
            x = 0;
            y += 8;
        }
    }
}