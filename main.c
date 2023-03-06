/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main BSQ
*/

#include "my_structs.h"
#include "my_functions.h"

int main(int ac, char **av)
{
    if (ac == 2){
        if (bsq(av[1]))
            return (84);
    }
    else
        return (84);
    return (0);
}
