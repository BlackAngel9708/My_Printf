/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for pointer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(pointer, test_19, .init=cr_redirect_stdout) {
    char expected[255];
    char fmt[] = "The pointer: %p\n";

    sprintf(expected, fmt, expected);
    my_printf(fmt, expected);
    cr_assert_stdout_eq_str(expected);
}
