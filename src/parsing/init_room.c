/*
** EPITECH PROJECT, 2020
** init_room.c
** File description:
** init_room
*/

#include "lemin.h"
#include <stdio.h>
#include "my.h"

void init_room(rooms_t *room, int len, char type)
{
    room->name[len] = 0;
    room->type = type;
    room->occupied = false;
    room->score = 0;
    room->links = NULL;
    room->is_proceeded = false;
}

int set_room(lemin_t *infos, char *str, char type)
{
    rooms_t *room = malloc(sizeof(rooms_t));
    int len = word_len(str, ' ');
    if (!room)
        return (ERROR_MALLOC);
    room->name = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++) {
        room->name[i] = *str;
        str = &str[1];
    }
    if (*str == 0)
        return (ERROR);
    init_room(room, len, type);
    room_set_coord(room, str);
    FOREACH(rooms_t, tmp, i, infos->map)
        if ((my_strcmp(tmp->name, room->name) == 0 && my_strlen(tmp->name)
        == my_strlen(room->name)) || (tmp->x == room->x && tmp->y == room->y))
            return (ERROR_FORMAT);
    ENDFOREACH(i, infos->map)
    lily_add_node(&infos->map, lily_create_node(room), 0);
    return (0);
}

int loop_for_ends(char *str, int *nb_tunnels, lemin_t *infos)
{
    size_t nb = 0;

    if (my_strcmp(str, "##start") == 0 && my_strlen(str) == 8) {
        while (*str == '#')
            if (getline(&str, &nb, stdin) < 2)
                return (ERROR);
        my_putstr("##start\n");
        if (set_room(infos, str, START))
            return (ERROR);
        (*nb_tunnels) += 1;
    } else if (my_strcmp(str, "##end") == 0 && my_strlen(str) == 6) {
        while (*str == '#')
            if (getline(&str, &nb, stdin) < 2)
                return (ERROR);
        my_putstr("##end\n");
        if (set_room(infos, str, END))
            return (ERROR);
        (*nb_tunnels) += 1;
    } else if (str[1] == '#')
        return (ERROR);
    return (0);
}

int read_loop(char *str, int *nb_tunnels, lemin_t *infos)
{
    int type = get_type(str);

    if (type == 0)
        return (ERROR);
    if (type == COMMENT)
        if (loop_for_ends(str, nb_tunnels, infos))
            return (ERROR);
    if (type == ROOM)
        if (set_room(infos, str, ROOM))
            return (ERROR);
    if (type == LINK) {
        if (*nb_tunnels == 2)
            my_putstr("#tunnels\n");
        if (*nb_tunnels <= 1)
            return (ERROR);
        if (set_links(infos, str))
            return (ERROR);
        *nb_tunnels = 3;
    }
    return (0);
}