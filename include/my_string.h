#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>


int    my_memcmp(const void*, const void*, size_t);
void*  my_memcpy(void*, const void*, size_t);
char*  my_strcat(char*, const char*);
char*  my_strchr(const char*, int);
int    my_strcmp(const char*, const char*);
char*  my_strcpy(char*, const char*);
size_t my_strcspn(const char *, const char *);
size_t my_strlen(const char*);

#endif