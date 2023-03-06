/*
** EPITECH PROJECT, 2019
** my_functions.h
** File description:
** classic header
*/


#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef FCT_H
#define FCT_H

//core.c
int bsq(char *path);

//create.c
int create_map(data_t *data);
int create_map_num(data_t *data);
int create_file(data_t *data);

//modif.c
int modif_map(data_t *data);
int modif_map_num(data_t *data);
void set_modif(data_t *data, int x, int y);

//disp.c
void my_putchar(char c);
int disp(data_t *data);

//tools.c
int read_file(data_t *data);
data_t *init_data(char *path);
void go_free(data_t *data);
int find_lenght_first_line(data_t *data);

//find.c
long find_size_file(char *path);
void find_height(data_t *data);
void find_width(data_t *data);
int find_smalest(int a, int b, int c);
void find_square(data_t *data);



#endif
