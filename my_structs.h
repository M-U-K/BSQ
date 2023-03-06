/*
** EPITECH PROJECT, 2019
** my_structs.h
** File description:
** classic header
*/

#ifndef STR_H
#define STR_H

typedef struct data_s
{
    int error;
    int x_square;
    int y_square;
    int size_square;
    long width;
    long height;
    long long size_file;
    char *buff;
    char *path;
    char *file;
    int **map_num;
    char **map;
}data_t;

#endif
