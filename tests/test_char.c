/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for char
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(char, normal, .init = cr_redirect_stdout) {
    my_printf("%c", 'h');
    cr_assert_stdout_eq_str("h");
}

Test(char, with_string, .init = cr_redirect_stdout) {
    my_printf("The char is: %c", 'm');
    cr_assert_stdout_eq_str("The char is: m");
}

Test(char, multiple, .init = cr_redirect_stdout) {
    my_printf("%c%c%c%c%c\n", 'h', 'e', 'l', 'l', 'o');
    cr_assert_stdout_eq_str("hello\n");
}
