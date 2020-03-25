/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pathfinding
*/

#include "lemin.h"
#include "lily.h"
#include "my.h"

void print_links(rooms_t *room)
{
    FOREACH(rooms_t, links, i, room->links)
        my_printf("from %s link %s\n", room->name, links->name);
    ENDFOREACH(i, room->links)
}

path_t proceed_room(rooms_t *room, rooms_t *prev_room)
{
    path_t best_path = {.room = NULL, .score = 999};
    path_t tmp;
    //my_printf("\nstart room %s\n", room->name);
    //print_links(room);

    if (prev_room)
        room->score = prev_room->score + (room->occupied ? 2 : 1);
    else
        room->score = 0;
    //my_printf("Room score %s: %d\n", room->name, room->score);
    if (room->type == END) {
        //my_printf("END SCORE: %i\n", room->score);
        best_path.score = room->score;
        best_path.room = room;
        return (best_path);
    }
    room->is_proceeded = true;
    FOREACH(rooms_t, r_linked, i, room->links)
        if (r_linked->is_proceeded) {
            CONTINUE(i);
        }
        r_linked->is_proceeded = true;
        tmp = proceed_room(r_linked, room);
        //my_printf("Curent: %s, Best: %d -- Foreach room: %s - score: %d\n", room->name, best_path.score, tmp.room->name, tmp.score);
        r_linked->is_proceeded = false;
        if (!best_path.room || tmp.score <= best_path.score) {
            best_path.room = r_linked;
            best_path.score = tmp.score;
            // my_printf("Changing %s's score: %d\n", best_path.room->name, best_room->score);
        }
    ENDFOREACH(i, room->links)
    room->is_proceeded = false;
    if (!best_path.room) {
        best_path.room = room;
        best_path.score = 999999999;
    }
   // my_printf("Best room score: %i\n", best_path.score);
    return (best_path);
}

rooms_t *get_best_room(ant_t *ant)
{
    if (!ant)
        return (NULL);
   // my_printf("\n\nfor ant %i (current room: %s)\n", ant->id, ant->current_room->name);
    return (proceed_room(ant->current_room, NULL).room);
}