#ifndef LCD2_H
#define LCD2_H

#include <stdint.h>

#include "LCDFont5x7.h"

typedef enum {
    LCD_BYTE_VERTICAL,
    LCD_BYTE_HORIZONTAL,
} LCD_ByteOrientation;

typedef enum {
    LCD_BYTE_MSB_FIRST,
    LCD_BYTE_LSB_FIRST,
} LCD_ByteOrder;

typedef struct {
    uint16_t width;
    uint16_t height;
    uint8_t *buffer;
} LCD_handle_t;

void LCD_clear(LCD_handle_t handle);

//TODO special function to draw string based on specific font
void LCD_string(LCD_handle_t handle, const char *string, uint8_t x, uint8_t y, bool wrap);

#endif //LCD2_H
