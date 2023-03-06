/*
** EPITECH PROJECT, 2019
** create.c
** File description:
** create BSQ
*/

#include "my_structs.h"
#include "my_functions.h"

int create_map(data_t *data)
{
    int x = 0;
    int y = 0;

    find_width(data);
    find_height(data);
    data->map = malloc(sizeof(char *) * (data->height));
    for (int i = 0; i != data->height; i++)
        data->map[i] = malloc(sizeof(char) * (data->width) + 1);
    for (int i = 0; data->file[i+1] != '\0';i++, y++) {
        if (data->file[i] == '\n') {
            data->map[x][y] = '\0';
            y = 0;
            x++;
            i++;
        }
        data->map[x][y] = data->file[i];
    }
    data->map[x][y] = '\0';
    return (0);
}

int create_map_num(data_t *data)
{
    int y = 0;

    data->map_num = malloc(sizeof(int *) * (data->height));
    for (int i = 0; i != data->height; i++)
        data->map_num[i] = malloc(sizeof(int) * (data->width)-1);
    for (int x = 0; x != data->height; x++) {
        for (y = 0; y != data->width-1; y++) {
            if (data->map[x][y] == '.')
                data->map_num[x][y] = 1;
            if (data->map[x][y] == 'o')
                data->map_num[x][y] = 0;
        }
        y = 0;
    }
    return (0);
}

int create_file(data_t *data)
{
    int i = 0;
    int lenght_first_line = find_lenght_first_line(data);

    data->file = malloc(sizeof(char) * \
(data->size_file - lenght_first_line + 1));
    for (; data->buff[lenght_first_line] != '\0'; i++, lenght_first_line++) {
        data->file[i] = data->buff[lenght_first_line];
    }
    data->file[i] = '\0';
    return (0);
}
