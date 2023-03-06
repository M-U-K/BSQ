/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tools BSQ
*/

#include "my_structs.h"
#include "my_functions.h"

int read_file(data_t *data)
{
    int fd = open(data->path, O_RDONLY);
    int offset = 0;
    int len;

    while ((len = read(fd, data->buff + offset, data->size_file - offset)) > 0)
        offset = offset + len;
    data->buff[offset] = '\0';
    if (len < 0)
        return (1);
    return (0);
}

data_t *init_data(char *path)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL)
        data->error = 1;
    data->size_file = find_size_file(path);
    data->path = path;
    data->buff = malloc(sizeof(char) * (data->size_file + 1));
    return (data);
}

void go_free(data_t *data)
{
    for (int i = 0; i != data->height; i++)
        free(data->map_num[i]);
    for (int i = 0; i != data->height; i++)
        free(data->map[i]);
    free(data->buff);
    free(data->file);
    free(data->map_num);
    free(data->map);
    free(data);
}

int find_lenght_first_line(data_t *data)
{
    int i = 0;

    for (; data->buff[i] != '\n'; i ++);
    return (i + 1);
}
