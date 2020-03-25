/*
** EPITECH PROJECT, 2020
** init_room.c
** File description:
** init_room
*/

#include "lemin.h"

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
    init_room(room, len, type);
    room_set_coord(room, str);
    FOREACH(rooms_t, tmp, i, infos->map)
        if (my_strcmp(tmp->name, room->name) == 0
        || (tmp->x == room->x && tmp->y == room->y))
            return (ERROR_FORMAT);
    ENDFOREACH(i, infos->map)
    lily_add_node(&infos->map, lily_create_node(room), 0);
    return (0);
}