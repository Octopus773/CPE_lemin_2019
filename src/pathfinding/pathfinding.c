/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pathfinding
*/

#include "lemin.h"
#include "lily.h"
#include "my.h"

rooms_t *proceed_room(rooms_t *room, rooms_t *prev_room)
{
    rooms_t *best_room;
    rooms_t *room_tmp;

    if (!room || !prev_room)
        return (NULL);
    room->score = prev_room->score + 1;
    best_room = room->links->data;
    FOREACH(rooms_t, rooms_linked, i, room->links)
        if (rooms_linked->type == END)
            return (i->data);
        if (!rooms_linked->occupied && !rooms_linked->is_proceeded && rooms_linked != prev_room) {
            rooms_linked->is_proceeded = true;
            room_tmp = proceed_room(i->data, room);
            if (room_tmp && room_tmp->score < best_room->score)
                best_room = room_tmp;
            rooms_linked->is_proceeded = false;
        }
    ENDFOREACH(i, room->links)
    return ((best_room->occupied) ? NULL : best_room);
}

rooms_t *get_best_room(ant_t *ant)
{
    if (!ant)
        return (NULL);
    return (proceed_room(ant->current_room->data, ant->old_room->data));
}