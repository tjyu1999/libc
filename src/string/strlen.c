#include "my_string.h"


size_t my_strlen(const char *s) {
    const char *sc = s;

    for (; *sc != '\0'; ++sc)
        ;
    return sc - s;
}