/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for float
*/

#include <stdio.h>
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

static
void cr_printf_test(char *fmt, double nbr)
{
    char expected[512] = { 0 };
    int expected_len = sprintf(expected, fmt, nbr);
    int got_len = my_printf(fmt, nbr);

    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(expected_len, got_len);
}

Test(flags, six_nine, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%f", 6.9);
}

Test(flags, og, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%f", 0.1 + 0.2);
}

Test(flags, precision, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%.3f", 2.8);
}

Test(flags, zero_precision, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%.0f", 2.8);
}

Test(flags, 300_precision, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%.300f", 2.8);
}

Test(flags, negative_precision, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%.-2f", 2.8);
}

Test(flags, negative_precision_v2, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%.-300f", 2.8);
}

Test(flags, minus_zero_precision, .init=cr_redirect_stdout) {
    cr_printf_test("hello world%.-0f", 2.8);
}
