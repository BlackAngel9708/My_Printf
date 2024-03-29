/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for octal
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(octal, test_19, .init=cr_redirect_stdout) {
    my_printf("I'm %o years old\n", 19);
    cr_assert_stdout_eq_str("I'm 23 years old\n");
}

Test(octal, multiple_int, .init=cr_redirect_stdout) {
    my_printf("I'm %o years old, and I have %o friends.\n", 19, 0);
    cr_assert_stdout_eq_str("I'm 23 years old, and I have 0 friends.\n");
}
