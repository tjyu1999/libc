#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "my_string.h"


static int total_count = 0;
static int pass_count = 0;

static int sign(int n) {
    return (n > 0) - (n < 0);
}

void print_result(const char *name, int pass) {
    total_count++;

    if (pass) {
        pass_count++;
        printf("%s\tPASS\n", name);
    }
    else
        printf("%s\tFAIL\n", name);
}

static void test_memcmp() {
    bool pass = true;
    const char *s1[] = {"1234", "1234"};
    const char *s2[] = {"1234", "1233"};
    const char *s3[] = {"abc", "abcde"};
    const char *s4[] = {"/////**", "/*/*/"};

    pass &= (sign(memcmp(s1[0], s1[1], 4)) == sign(my_memcmp(s1[0], s1[1], 4)));
    pass &= (sign(memcmp(s2[0], s2[1], 4)) == sign(my_memcmp(s2[0], s2[1], 4)));
    pass &= (sign(memcmp(s3[0], s3[1], 3)) == sign(my_memcmp(s3[0], s3[1], 3)));
    pass &= (sign(memcmp(s4[0], s4[1], 7)) == sign(my_memcmp(s4[0], s4[1], 7)));
    print_result("memcmp", pass);
}

static void test_memcpy() {
    bool pass = true;
    char ref[10];
    char my[10];
    const char *s1 = "abc";
    const char *s2 = "/ * / * /";
    const char *s3 = "XxYyZz";

    pass &= (memcmp(memcpy(ref, s1, 3), my_memcpy(my, s1, 3), 3)) == 0;
    pass &= (memcmp(memcpy(ref, s2, 9), my_memcpy(my, s2, 9), 9)) == 0;
    pass &= (memcmp(memcpy(ref, s3, 6), my_memcpy(my, s3, 6), 6)) == 0;
    print_result("memcpy", pass);
}

static void test_strchr() {
    bool pass = true;
    const char *s1 = "Hello world!";
    const char *s2 = "bbbbb";
    const char *s3 = "123\n";
    int c1 = 'w';
    int c2 = 'b';
    int c3 = '\\';

    pass &= (strchr(s1, c1) == my_strchr(s1, c1));
    pass &= (strchr(s2, c2) == my_strchr(s2, c2));
    pass &= (strchr(s3, c3) == my_strchr(s3, c3));
    print_result("strchr", pass);
}

static void test_strcmp() {
    bool pass = true;
    const char *s1[] = {"abc", "abc"};
    const char *s2[] = {"abc", "a\t\n"};
    const char *s3[] = {"abc", "abcde"};

    pass &= (sign(strcmp(s1[0], s1[1])) == sign(my_strcmp(s1[0], s1[1])));
    pass &= (sign(strcmp(s2[0], s2[1])) == sign(my_strcmp(s2[0], s2[1])));
    pass &= (sign(strcmp(s3[0], s3[1])) == sign(my_strcmp(s3[0], s3[1])));
    print_result("strcmp", pass);
}

static void test_strlen() {
    bool pass = true;
    const char *s1 = "";
    const char *s2 = "Hello world!";
    const char *s3 = "aaaaaaaaaaaaaaaaaaaa";
    const char *s4 = "1\t2\n3";

    pass &= (strlen(s1) == my_strlen(s1));
    pass &= (strlen(s2) == my_strlen(s2));
    pass &= (strlen(s3) == my_strlen(s3));
    pass &= (strlen(s4) == my_strlen(s4));
    print_result("strlen", pass);
}

int main() {
    test_memcmp();
    test_memcpy();
    // test_strcat();
    test_strchr();
    test_strcmp();
    // test_strcpy();
    test_strlen();

    printf("\nTotal\t%d/%d\n\n", pass_count, total_count);
    return 0;
}