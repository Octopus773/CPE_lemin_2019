/*
** EPITECH PROJECT, 2020
** get_nb_ants.c
** File description:
** get_nb_ants
*/

#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <stdlib.h>

int check_nb_ants(char *str)
{
    for (int i = 0; str[i] && str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (ERROR_FORMAT);
    return (0);
}

int get_nb_ants(lemin_t *infos)
{
    char *str = NULL;
    size_t nb = 0;

    if (getline(&str, &nb, stdin) < 0)
        return (ERROR_READ);
    if (check_nb_ants(str) != 0)
        return (ERROR_FORMAT);
    infos->nb_ant = my_getnbr(str);
    my_putstr("#number_of_ants\n");
    my_put_nbr(infos->nb_ant);
    my_putchar('\n');
    free(str);
    return (0);
}
