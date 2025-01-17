/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** my_compute_power_rec
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int tmp = nb;
    int res = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    tmp = my_compute_power_rec(nb, p - 1);
    res *= tmp;
    if (nb < 0 && tmp < 0 && res < 0)
        return 0;
    if (nb < 0 && tmp > 0 && res > 0)
        return 0;
    if (nb > 0 && res < 0)
        return 0;
    return res;
}
