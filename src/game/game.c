/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** game
*/

#include "lemin.h"
#include "my.h"
#include <unistd.h>
#include <stdbool.h>

bool move_ant(ant_t *ant)
{
    bool move_made = false;
    rooms_t *tmp;

    tmp = get_best_room(ant);
    if (tmp) {
        my_printf("get room %s for ant %i\n", tmp->name, ant->id);
        ant->old_room = ant->current_room;
        ant->current_room = tmp;
    }
    // SHOULD USE PATHFINDING HERE.
    if (ant->current_room != ant->old_room) {
        my_printf("P%d-%s", ant->id, ant->current_room->name);
        move_made = true;
    }
    ant->old_room = ant->current_room;
    return (move_made);
}

bool play_a_turn(ant_t *ants, rooms_t *end_room)
{
    bool done = true;
    bool move_made = false;

    for (int i = 0; ants[i].id >= 0; i++) {
        if (ants[i].current_room == end_room)
            continue;
        if (move_made)
            write(1, " ", 1);
        move_made = move_ant(&ants[i]) || move_made;
        done = false;
    }
    if (!done && move_made)
        write(1, "\n", 1);
    return (!done);
}