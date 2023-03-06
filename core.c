/*
** EPITECH PROJECT, 2019
** core.c
** File description:
** core BSQ
*/

#include "my_structs.h"
#include "my_functions.h"

int gest_error2(data_t *data)
{
    int y = 0;
    int i = 0;
    int cmp = 0;
    int	i2 = 0;

    for	(; data->buff[y] != '\n'; y++);
    i = y+1;
    y++;
    for (; data->buff[y] != '\n'; y++);
    i2 = y - i+1;
    y = i;
    for (; data->buff[y] != '\0'; y++) {
        cmp++;
        if (data->buff[y] == '\n' && cmp != i2)
            return (1);
        if (data->buff[y] == '\n')
            cmp = 0;
    }
    return (0);
}

int gest_error(data_t *data)
{
    int i = 0;

    if (data->buff[0] < 48 || data->buff[0] > 59)
        return (1);
    for (; data->buff[i] != '\n'; i++);
    if (data->buff[i+1] == NULL)
        return (1);
    for (; data->buff[i] != '\0'; i++)
        if (data->buff[i] != '.' && data->buff[i]\
!= '\n' && data->buff[i] != '\0' && data->buff[i] != 'o')
            return (1);
    if (gest_error2(data))
        return (1);
    return (0);
}

int bsq(char *path)
{
    data_t *data = init_data(path);

    if (data->error == 1)
        return (1);
    if (read_file(data))
        return (1);
    if (gest_error(data))
        return (1);
    if (create_file(data))
        return (1);
    if (create_map(data))
        return (1);
    create_map_num(data);
    if (modif_map_num(data))
        return (1);
    if (modif_map(data))
        return (1);
    disp(data);
    go_free(data);
    return (0);
}
