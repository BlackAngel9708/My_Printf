/*
** EPITECH PROJECT, 2023
** My printf
** File description:
** get_color
*/

#include <stdlib.h>
#include <stddef.h>

#include "my.h"

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    return (red << 16) + (green << 8) + blue;
}
