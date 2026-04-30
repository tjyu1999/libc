#include "my_stdio.h"


int my_putchar(int c) {
    return fputc(c, stdout);
}