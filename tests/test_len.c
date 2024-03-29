/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for len
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(len, hello_world, .init=cr_redirect_stdout) {
    int got = -1;
    int expected = -1;
    char fmt[] = "hello world%n";

    my_printf(fmt, &got);
    printf(fmt, &expected);
    cr_assert_eq(got, expected);
}

Test(len, hello, .init=cr_redirect_stdout) {
    int got = -1;
    int expected = -1;
    char fmt[] = "Hello%n world";

    my_printf(fmt, &got);
    printf(fmt, &expected);
    cr_assert_eq(got, expected);
}

Test(len, int, .init=cr_redirect_stdout) {
    int got = -1;
    int expected = -1;
    char fmt[] = "Hello%d%n";

    my_printf(fmt, 345678, &got);
    printf(fmt, 345678, &expected);
    cr_assert_eq(got, expected);
}

Test(len, ziak, .init=cr_redirect_stdout) {
    int got = -1;
    int expected = -1;
    char *fmt = (
        "Zipette, zipette, elle fait une fixette sur ma %s,\n"
        "A6, A7 je fais le tour de France je suis ré-bou.%n\n"
    );

    my_printf(fmt, "poutre", &got);
    printf(fmt, "poutre", &expected);
    cr_assert_eq(got, expected);
}

Test(len, hexa, .init=cr_redirect_stdout) {
    int got = -1;
    int expected = -1;
    char fmt[] = "Hello%x%n world";

    my_printf(fmt, 12345678, &got);
    printf(fmt, 12345678, &expected);
    cr_assert_eq(got, expected);
}
