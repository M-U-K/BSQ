/*
** EPITECH PROJECT, 2019
** find.c
** File description:
** find BSQ
*/

#include "my_structs.h"
#include "my_functions.h"

long find_size_file(char *path)
{
    struct stat inf_text;

    if (stat(path, &inf_text) == - 1){}
    return (inf_text.st_size);
}

void find_height(data_t *data)
{
    int i = 0;
    int cmp = 0;

    for (; data->file[i] != '\0'; i ++) {
        if (data->file[i] == '\n')
            cmp ++;
    }
    data->height = cmp;
}

void find_width(data_t *data)
{
    int i = 0;

    for (; data->file[i] != '\n'; i ++);
    data->width = i+1;
}

int find_smalest(int a, int b, int c)
{
    if (a <= b && a <= c)
        return (a);
    if (b <= c && b <= a)
        return (b);
    if (c <= a && c <= b)
        return (c);
    return (0);
}

void find_square(data_t *data)
{
    data->size_square = 0;
    for (int x = 0; x != data->height; x++) {
        for (int y = 0; y != data->width; y++) {
            if (data->map_num[x][y] > data->size_square) {
                data->size_square = data->map_num[x][y];
                data->x_square = x+1;
                data->y_square = y+1;
            }
        }
    }
}
