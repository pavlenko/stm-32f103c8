#include <stdint.h>

#include "PCD8544_2.h"

int main()
{
    PCD8544_initialize();
    PCD8544_clear();
    PCD8544_string("HELLO");
}
