/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int res = 0;

    if (!str)
        return 0;
    while (str[res])
        res++;
    return res;
}