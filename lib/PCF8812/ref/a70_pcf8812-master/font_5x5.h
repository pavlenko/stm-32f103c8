#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef FONT_5x5_H
#define FONT_5x5_H

//*************************//шрифт 5x8 в програмной памяти*****************  
static const uint8_t font_5x5[] PROGMEM= 
{
	0x07, // 7  - кол-во байт параметров
	0x08, // 16 - разрядность
	0x05, // 5  - ширина
	0x08, // 5  - высота 
	0x02, // 02 - идентификатор
	0x20, // 32 - первый чар ))
	0x7F, // 127- последний чар
  0x00, 0x00, 0x00, 0x00, 0x00,// (space)
  0x00, 0x00, 0x5E, 0x00, 0x00,// !
  0x00, 0x0C, 0x00, 0x0C, 0x00,// "
  0x28, 0x7C, 0x28, 0x7C, 0x28,// #
  0x48, 0x54, 0x7C, 0x54, 0x24,// $
  0x4C, 0x2C, 0x10, 0x68, 0x64,// %
  0x20, 0x58, 0x54, 0x68, 0x40,// &
  0x00, 0x00, 0x0C, 0x00, 0x00,// '
  0x00, 0x00, 0x38, 0x44, 0x00,// (
  0x00, 0x44, 0x38, 0x00, 0x00,// )
  0x00, 0x28, 0x10, 0x28, 0x00,// *
  0x00, 0x10, 0x38, 0x10, 0x00,// +
  0x00, 0x00, 0xC0, 0x00, 0x00,// ,
  0x00, 0x10, 0x10, 0x10, 0x00,// -
  0x00, 0x00, 0x40, 0x00, 0x00,// .
  0x00, 0x60, 0x10, 0x0C, 0x00,// /
  0x38, 0x44, 0x44, 0x44, 0x38,// 0
  0x00, 0x44, 0x7C, 0x40, 0x00,// 1
  0x74, 0x54, 0x54, 0x54, 0x5C,// 2
  0x44, 0x54, 0x54, 0x54, 0x7C,// 3
  0x1C, 0x10, 0x10, 0x10, 0x7C,// 4
  0x5C, 0x54, 0x54, 0x54, 0x74,// 5
  0x7C, 0x54, 0x54, 0x54, 0x74,// 6
  0x04, 0x04, 0x64, 0x14, 0x0C,// 7
  0x7C, 0x54, 0x54, 0x54, 0x7C,// 8
  0x5C, 0x54, 0x54, 0x54, 0x7C,// 9
  0x00, 0x00, 0x48, 0x00, 0x00,// :
  0x00, 0x00, 0xC8, 0x00, 0x00,// ;
  0x00, 0x10, 0x28, 0x44, 0x00,// <
  0x00, 0x28, 0x28, 0x28, 0x00,// =
  0x00, 0x44, 0x28, 0x10, 0x00,// >
  0x08, 0x04, 0xA4, 0x14, 0x08,// ?
  0x38, 0x44, 0x54, 0x54, 0x08,// @
  0x78, 0x14, 0x14, 0x14, 0x78,// A
  0x7C, 0x54, 0x54, 0x54, 0x28,// B
  0x38, 0x44, 0x44, 0x44, 0x44,// C
  0x7C, 0x44, 0x44, 0x44, 0x38,// D
  0x7C, 0x54, 0x54, 0x54, 0x44,// E
  0x7C, 0x14, 0x14, 0x14, 0x04,// F
  0x7C, 0x44, 0x44, 0x54, 0x74,// G
  0x7C, 0x10, 0x10, 0x10, 0x7C,// H
  0x00, 0x44, 0x7C, 0x44, 0x00,// I
  0x20, 0x40, 0x40, 0x40, 0x3C,// J
  0x7C, 0x10, 0x10, 0x28, 0x44,// K
  0x7C, 0x40, 0x40, 0x40, 0x60,// L
  0x7C, 0x08, 0x10, 0x08, 0x7C,// M
  0x7C, 0x08, 0x10, 0x20, 0x7C,// N
  0x38, 0x44, 0x44, 0x44, 0x38,// O
  0x7C, 0x14, 0x14, 0x14, 0x1C,// P
  0x38, 0x44, 0x44, 0x64, 0x78,// Q
  0x7C, 0x14, 0x14, 0x34, 0x5C,// R
  0x48, 0x54, 0x54, 0x54, 0x24,// S
  0x04, 0x04, 0x7C, 0x04, 0x04,// T
  0x3C, 0x40, 0x40, 0x40, 0x3C,// U
  0x0C, 0x30, 0x40, 0x30, 0x0C,// V
  0x3C, 0x40, 0x38, 0x40, 0x3C,// W
  0x44, 0x28, 0x10, 0x28, 0x44,// X
  0x04, 0x08, 0x70, 0x08, 0x04,// Y
  0x44, 0x64, 0x54, 0x4C, 0x44,// Z
  0x00, 0x00, 0x7C, 0x44, 0x00,// [
  0x00, 0x0C, 0x10, 0x60, 0x00,// "\"
  0x00, 0x44, 0x7C, 0x00, 0x00,// ]
  0x00, 0x08, 0x04, 0x08, 0x00,// ^
  0x40, 0x40, 0x40, 0x40, 0x40,// _
  0x00, 0x00, 0x04, 0x08, 0x00,// `
  0x20, 0x54, 0x54, 0x24, 0x78,// a
  0x78, 0x50, 0x50, 0x50, 0x20,// b
  0x30, 0x48, 0x48, 0x48, 0x48,// c
  0x20, 0x50, 0x50, 0x50, 0x78,// d
  0x30, 0x58, 0x58, 0x58, 0x10,// e
  0x00, 0x08, 0x7E, 0x0A, 0x00,// f
  0x10, 0xA8, 0xA8, 0xA8, 0x70,// g
  0x78, 0x20, 0x10, 0x10, 0x60,// h
  0x00, 0x00, 0x74, 0x00, 0x00,// i
  0x00, 0x20, 0x40, 0x34, 0x00,// j
  0x78, 0x10, 0x30, 0x28, 0x40,// k
  0x00, 0x44, 0x7C, 0x40, 0x00,// l
  0x78, 0x08, 0x70, 0x08, 0x70,// m
  0x78, 0x10, 0x08, 0x08, 0x70,// n
  0x30, 0x48, 0x48, 0x48, 0x30,// o
  0x78, 0x28, 0x28, 0x28, 0x10,// p
  0x30, 0x48, 0x48, 0x48, 0xB0,// q
  0x78, 0x10, 0x08, 0x08, 0x10,// r
  0x40, 0x58, 0x68, 0x08, 0x00,// s
  0x00, 0x08, 0x7E, 0x48, 0x00,// t
  0x38, 0x40, 0x40, 0x20, 0x78,// u
  0x08, 0x30, 0x40, 0x30, 0x08,// v
  0x38, 0x40, 0x20, 0x40, 0x38,// w
  0x48, 0x30, 0x30, 0x30, 0x48,// x
  0x08, 0x50, 0x20, 0x10, 0x08,// y
  0x48, 0x68, 0x58, 0x48, 0x00,// z
  0x00, 0x10, 0x38, 0x44, 0x00,// {
  0x00, 0x00, 0xFE, 0x00, 0x00,// |
  0x00, 0x44, 0x38, 0x10, 0x00,// }
  0x10, 0x10, 0x54, 0x38, 0x10,// ->
  0x10, 0x38, 0x54, 0x10, 0x10 // <-
};
#endif;