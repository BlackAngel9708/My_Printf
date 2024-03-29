/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for padding
*/

#include <stdio.h>
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

static
void cr_printf_test(char *fmt, int nbr)
{
    char expected[255] = { 0 };
    int expected_len = sprintf(expected, fmt, nbr);
    int got_len = my_printf(fmt, nbr);

    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(expected_len, got_len);
}

Test(flags, dec_positive, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%5d", 69);
}

Test(flags, dec_negative, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%-5d", 420);
}

Test(flags, oct_positive, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%5o", 69);
}

Test(flags, oct_negative, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%-5o", 420);
}

Test(flags, hex_positive, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%5x", 69);
}

Test(flags, hex_negative, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%-5x", 420);
}

Test(flags, HEX_positive, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%5X", 69);
}

Test(flags, HEX_negative, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%-5X", 420);
}

Test(flags, 0x_positive, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%#50x", 69);
}

Test(flags, 0x_negative, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%#-50x", 420);
}

Test(flags, 0X_positive, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%#50X", 69);
}

Test(flags, 0X_negative, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%#-50X", 420);
}
