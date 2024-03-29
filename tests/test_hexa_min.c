/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for hexa_min
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(hexa_min, test_19, .init=cr_redirect_stdout) {
    my_printf("I'm %x years old\n", 19);
    cr_assert_stdout_eq_str("I'm 13 years old\n");
}

Test(hexa_min, multiple_int, .init=cr_redirect_stdout) {
    my_printf("I'm %x years old, and I have %x friends.\n", 678, 0);
    cr_assert_stdout_eq_str("I'm 2a6 years old, and I have 0 friends.\n");
}
