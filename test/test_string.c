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
    char exp[100] = "";
    char act[100] = "";
    const char *s1 = "abc";
    const char *s2 = "/ * / * /";
    const char *s3 = "XxYyZz";

    pass &= (memcmp(memcpy(exp, s1, 3), my_memcpy(act, s1, 3), 3)) == 0;
    pass &= (memcmp(memcpy(exp, s2, 9), my_memcpy(act, s2, 9), 9)) == 0;
    pass &= (memcmp(memcpy(exp, s3, 6), my_memcpy(act, s3, 6), 6)) == 0;
    print_result("memcpy", pass);
}

static void test_strcat() {
    bool pass = true;
    char exp[100] = "";
    char act[100] = "";
    const char *s1 = "!@#$^&*";
    const char *s2 = "abc";
    const char *s3 = "";

    pass &= (strcmp(strcat(exp, s1), my_strcat(act, s1))) == 0;
    pass &= (strcmp(strcat(exp, s2), my_strcat(act, s2))) == 0;
    pass &= (strcmp(strcat(exp, s3), my_strcat(act, s3))) == 0;
    print_result("strcat", pass);
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

static void test_strcpy() {
    bool pass = true;
    char exp[100] = "";
    char act[100] = "";
    const char *s1 = "abc";
    const char *s2 = "iiiiiiiiii";
    const char *s3 = "/t/n123456789";

    pass &= (strcmp(strcpy(exp, s1), my_strcpy(act, s1))) == 0;
    pass &= (strcmp(strcpy(exp, s2), my_strcpy(act, s2))) == 0;
    pass &= (strcmp(strcpy(exp, s3), my_strcpy(act, s3))) == 0;
    print_result("strcpy", pass);
}

static void test_strcspn() {
    bool pass = true;
    const char *s1[] = {"Hello, world!", ","};
    const char *s2[] = {"qqqqq", "q"};
    const char *s3[] = {"\n\r\t", "\\"};
    const char *s4[] = {"abcde", "bcd"};

    pass &= (strcspn(s1[0], s1[1]) == my_strcspn(s1[0], s1[1]));
    pass &= (strcspn(s2[0], s2[1]) == my_strcspn(s2[0], s2[1]));
    pass &= (strcspn(s3[0], s3[1]) == my_strcspn(s3[0], s3[1]));
    pass &= (strcspn(s4[0], s4[1]) == my_strcspn(s4[0], s4[1]));
    print_result("strcspn", pass);
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
    test_strcat();
    test_strchr();
    test_strcmp();
    test_strcpy();
    test_strcspn();
    test_strlen();

    printf("\nTotal\t%d/%d\n\n", pass_count, total_count);
    return 0;
}