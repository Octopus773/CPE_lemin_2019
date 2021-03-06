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
    rooms_t *new_room = get_best_room(ant);

    if (!new_room->occupied && new_room->type != START) {
        ant->current_room->occupied = false;
        if (new_room->type != END)
            new_room->occupied = true;
        ant->old_room = ant->current_room;
        ant->current_room = new_room;
        my_printf("P%d-%s", ant->id, ant->current_room->name);
        return (true);
    }
    return (false);
}

bool play_a_turn(ant_t *ants, rooms_t *end_room)
{
    bool done = true;
    bool move_made = false;
    static bool played_last_turn = false;

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
    if (!played_last_turn && !move_made) {
        my_printf("Too bad, the ants are stuck. Leave the anthill now.\n");
        return (false);
    }
    played_last_turn = move_made;
    return (!done);
}