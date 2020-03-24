/*
** EPITECH PROJECT, 2020
** parsing1.c
** File description:
** parsing1
*/

#include "lemin.h"
#include <stdlib.h>

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
    if (get_rooms(infos) != 0)
        return (NULL);
    return (infos);
}