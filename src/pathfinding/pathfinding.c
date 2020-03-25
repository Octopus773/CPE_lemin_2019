/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pathfinding
*/

#include "lemin.h"
#include "lily.h"
#include "my.h"

static inline rooms_t *find_best_neighbour(rooms_t *room)
{
    rooms_t *best_room = NULL;
    unsigned best_score;
    rooms_t *neighbour;

    room->is_proceeded = true;
    FOREACH(rooms_t, r_linked, i, room->links)
        if (r_linked->is_proceeded) {
            CONTINUE(i);
        }
        neighbour = proceed_room(r_linked, room);
        if (!best_room || neighbour->score <= best_score) {
            best_room = r_linked;
            best_score = neighbour->score;
        }
    ENDFOREACH(i, room->links)
    room->is_proceeded = false;
    if (best_room)
        best_room->score = best_score;
    return (best_room);
}

rooms_t *proceed_room(rooms_t *room, rooms_t *prev_room)
{
    rooms_t *best_room = NULL;

    if (prev_room)
        room->score = prev_room->score + (room->occupied ? 2 : 1);
    else
        room->score = 0;
    if (room->type == END)
        return (room);
    best_room = find_best_neighbour(room);
    if (!best_room) {
        best_room = room;
        best_room->score = 999999999;
    }
    return (best_room);
}

rooms_t *get_best_room(ant_t *ant)
{
    if (!ant)
        return (NULL);
    return (proceed_room(ant->current_room, NULL));
}