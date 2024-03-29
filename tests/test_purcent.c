/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** tests for purcent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_printf.h"

Test(purcent, normal, .init = cr_redirect_stdout) {
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(purcent, multiple, .init = cr_redirect_stdout) {
    my_printf("%%%%%%%%%%%%%%");
    cr_assert_stdout_eq_str("%%%%%%%");
}

Test(purcent, with_char, .init = cr_redirect_stdout) {
    my_printf("%%%%%%%c%%%%%%", 'h');
    cr_assert_stdout_eq_str("%%%h%%%");
}
