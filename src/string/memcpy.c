#include "my_string.h"


void* my_memcpy(void *s1, const void *s2, size_t n) {
    char *su1 = (char*)s1;
    const char *su2 = (char*)s2;

    for (; n > 0; ++su1, ++su2, --n)
        *su1 = *su2;
    return s1;
}