#ifndef LCD2_H
#define LCD2_H

#include <stdint.h>

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
} LCD_config_t;

typedef struct {
    LCD_config_t config;
    uint8_t *buffer;
} LCD_handle_t;

void LCD_clear(LCD_handle_t handle);

#endif //LCD2_H
