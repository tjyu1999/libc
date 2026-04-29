#include "my_string.h"


char* my_strcat(char *s1, const char *s2) {
    char *s = s1;

    for (; *s != '\0'; ++s)
        ;
    for (; (*s = *s2) != '\0'; ++s, ++s2)
        ;
    return s1;
}