/*
** EPITECH PROJECT, 2020
** parsing1.c
** File description:
** parsing1
*/

#include "my.h"
#include "lemin.h"
#include <stdlib.h>

int get_nb_ants(lemin_t *infos);

int get_rooms(lemin_t *infos);

lemin_t *alloc_infos(void)
{
    lemin_t *infos = malloc(sizeof(lemin_t));

    if (!infos)
        return (NULL);
    infos->nb_ant = -1;
    infos->map = NULL;
    return (infos);
}

lemin_t *get_lemin(void)
{
    lemin_t *infos = alloc_infos();

    if (!infos)
        return (NULL);
    if (get_nb_ants(infos) != 0)
        return (NULL);
    my_putstr("#rooms\n");
    if (get_rooms(infos) != 0)
        return (NULL);
    return (infos);
}