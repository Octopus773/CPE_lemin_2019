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

void move_ant(ant_t *ant)
{
    rooms_t *room;

    // SHOULD USE PATHFINDING HERE.
    room = ant->current_room->data;
    my_printf("P%d-%s", ant->id, room->name);
}

bool play_a_turn(ant_t *ants, lily_list *end_room)
{
    bool done = true;

    for (int i = 0; ants[i].id >= 0; i++) {
        if (ants[i].current_room == end_room)
            continue;
        move_ant(&ants[i]);
    }
    if (!done)
        write(1, "\n", 1);
    return (!done);
}