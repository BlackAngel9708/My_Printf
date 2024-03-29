/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for unsigned
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(unsigned, test_19, .init=cr_redirect_stdout) {
    my_printf("I'm %u years old\n", 19);
    cr_assert_stdout_eq_str("I'm 19 years old\n");
}

Test(unsigned, multiple_int, .init=cr_redirect_stdout) {
    my_printf("I'm %u years old, and I have %u friends.\n", 19, 0);
    cr_assert_stdout_eq_str("I'm 19 years old, and I have 0 friends.\n");
}
