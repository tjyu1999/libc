#include "my_string.h"


int my_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *su1 = (const unsigned char*)s1;
    const unsigned char *su2 = (const unsigned char*)s2;

    for (; n > 0; ++su1, ++su2, --n) {
        if (*su1 != *su2)
            return *su1 - *su2;
    }
    return 0;
}