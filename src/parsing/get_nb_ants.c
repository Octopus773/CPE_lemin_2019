/*
** EPITECH PROJECT, 2020
** get_nb_ants.c
** File description:
** get_nb_ants
*/

#include "lemin.h"
#include "my.h"
#include <stdio.h>
#include <malloc.h>

int check_nb_ants(char *str, lemin_t *infos)
{
    for (int i = 0; str[i] && str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (ERROR_FORMAT);
    (void)infos;
    return (0);
}

int get_nb_ants(lemin_t *infos)
{
    char *str = NULL;
    size_t nb = 0;

    if (getline(&str, &nb, stdin) < 0)
        return (ERROR_READ);
    if (check_nb_ants(str, infos) != 0)
        return (ERROR_FORMAT);
    infos->nb_ant = my_getnbr(str);
    free(str);
    return (0);
}
