/*
** EPITECH PROJECT, 2019
** modif.c
** File description:
** modif BSQ
*/

#include "my_structs.h"
#include "my_functions.h"

int modif_map(data_t *data)
{
    find_square(data);
    for (int x = 0; x != data->size_square; x ++) {
        for (int y = 0; y != data->size_square; y ++) {
            data->map[data->x_square-data->size_square+x]\
[data->y_square-data->size_square+y] = 'x';
        }
    }
    return (0);
}

int modif_map_num(data_t *data)
{
    int x = 0;
    int y = 0;

    for (; x != data->height; x++) {
        for (y = 0; y != data->width-1; y++) {
            if (x > 0 && y > 0 && data->map_num[x][y] != 0) {
                set_modif(data, x, y);
            }
        }
    }
    return (0);
}

void set_modif(data_t *data, int x, int y)
{
    if (data->map_num[x-1][y] != 0 && data->map_num[x][y-1] \
!= 0 && data->map_num[x-1][y-1] != 0 && data->map_num[x-1][y] \
== data->map_num[x][y-1] && data->map_num[x-1][y] == \
data->map_num[x-1][y-1] && data->map_num[x][y-1] == data->map_num[x-1][y-1])
        data->map_num[x][y] = data->map_num[x-1][y] + 1;
    if ((data->map_num[x-1][y-1] != 0 && data->map_num[x-1][y]\
!= 0 && data->map_num[x][y-1] != 0 && data->map_num[x-1][y] != \
data->map_num[x][y-1]) || data->map_num[x-1][y] != data->map_num[x-1][y-1] \
|| data->map_num[x][y-1] != data->map_num[x-1][y-1])
        data->map_num[x][y] = find_smalest(data->map_num[x-1][y], \
data->map_num[x][y-1], data->map_num[x-1][y-1]) + 1;
}
