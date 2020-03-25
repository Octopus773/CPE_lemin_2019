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
    rooms_t *best_room = NULL;
    int best_score = -1;
    rooms_t *tmp;

    if (prev_room)
        room->score = prev_room->score + (room->occupied ? 2 : 1);
    else
        room->score = 0;
    // my_printf("Room score %s: %d\n", room->name, room->score);
    if (room->type == END)
        return (room);
    room->is_proceeded = true;
    FOREACH(rooms_t, r_linked, i, room->links)
        if (r_linked->is_proceeded) {
            CONTINUE(i);
        }
        r_linked->is_proceeded = true;
        tmp = proceed_room(r_linked, room);
        // my_printf("Curent: %s, Best: %d -- Foreach room: %s - score: %d\n", room->name, best_score, tmp->name, tmp->score);
        r_linked->is_proceeded = false;
        if (!best_room || tmp->score <= best_score) {
            best_room = r_linked;
            best_score = tmp->score;
        }
    ENDFOREACH(i, room->links)
    room->is_proceeded = false;
    if (!best_room) {
        best_room = room;
        best_score = 999999999;
    }
    best_room->score = best_score;
    // my_printf("Best room score: %i\n", best_room->score);
    return (best_room);
}

rooms_t *get_best_room(ant_t *ant)
{
    if (!ant)
        return (NULL);
    // my_printf("\n\nfor ant %i (current room: %s)\n", ant->id, ant->current_room->name);
    return (proceed_room(ant->current_room, NULL));
}