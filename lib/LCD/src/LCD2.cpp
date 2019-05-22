#include "LCD2.h"

void LCD_clear(LCD_handle_t handle)
{
    for (uint16_t i = 0; i < sizeof(handle.buffer); i++) {
        *(handle.buffer + i) = 0x00u;
    }
}
