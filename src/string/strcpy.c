#include "my_string.h"


char* my_strcpy(char *s1, const char *s2) {
    char *s = s1;

    for (; (*s = *s2) != '\0'; ++s, ++s2)
        ;
    return s1;
}