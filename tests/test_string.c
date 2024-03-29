/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(string, normal, .init = cr_redirect_stdout) {
    my_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(string, with_string, .init = cr_redirect_stdout) {
    my_printf("The string is: `%s`", "bob");
    cr_assert_stdout_eq_str("The string is: `bob`");
}

Test(string, multiple, .init = cr_redirect_stdout) {
    my_printf("%s%s!\n", "hello", "world");
    cr_assert_stdout_eq_str("helloworld!\n");
}
