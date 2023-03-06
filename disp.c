/*
** EPITECH PROJECT, 2019
** disp.c
** File description:
** disp BSQ
*/

#include "my_structs.h"
#include "my_functions.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int disp(data_t *data)
{
    int i = 0;
    for (int x = 0; x != data->height; x++) {
        write(1, data->map[x], data->width-1);
        my_putchar('\n');
    }
    return (0);
}
