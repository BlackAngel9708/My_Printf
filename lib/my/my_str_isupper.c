/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** my_str_isupper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!IS_UPPERCASE(str[i]))
            return 0;
    return 1;
}
