/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(int, test_19, .init=cr_redirect_stdout) {
    int len = my_printf("I'm %d years old\n", 19);
    cr_assert_eq(len, 17);
    cr_assert_stdout_eq_str("I'm 19 years old\n");
}

Test(int, multiple_int, .init=cr_redirect_stdout) {
    int len = my_printf("I'm %d years old, and I have %d friends.\n", 19, 0);
    cr_assert_eq(len, 40);
    cr_assert_stdout_eq_str("I'm 19 years old, and I have 0 friends.\n");
}
