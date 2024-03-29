/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

void char_swap(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}
