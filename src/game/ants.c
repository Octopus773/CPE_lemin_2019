/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** ants
*/

#include "lemin.h"
#include "lily.h"
#include <stddef.h>

lily_list *get_start_room(lemin_t *lemin)
{
    if (!lemin)
        return (NULL);
    FOREACH(rooms_t, room, i, lemin->map)
        if (room->type == START)
            return (i);
    ENDFOREACH(i, lemin->map)
    return (NULL);
}

lily_list *get_end_room(lemin_t *lemin)
{
    if (!lemin)
        return (NULL);
    FOREACH(rooms_t, room, i, lemin->map)
        if (room->type == END)
            return (i);
    ENDFOREACH(i, lemin->map)
    return (NULL);
}

ant_t *get_ants(lemin_t *lemin)
{
    static int id = 1;
    ant_t *ants;
    lily_list *start_room = get_start_room(lemin);

    if (!lemin || !start_room)
        return (NULL);
    ants = malloc(sizeof(*ants) * (lemin->nb_ant + 1));
    if (!ants)
        return (NULL);
    for (unsigned i = 0; i < lemin->nb_ant; i++) {
        ants[i].id = id++;
        ants[i].current_room = start_room;
    }
    ants[lemin->nb_ant].id = -1;
    ants[lemin->nb_ant].current_room = NULL;
    return (ants);
}