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

rooms_t *proceed_room(rooms_t *room, rooms_t *prev_room)
{
    rooms_t *best_room = NULL;
    rooms_t *tmp;
    //my_printf("\nstart room %s\n", room->name);
    //print_links(room);

    if (prev_room)
        room->score = prev_room->score + (room->occupied) ? 2 : 1;
    if (room->type == END) {
       // my_printf("END SCORE: %i\n", room->score);
        return (room);
    }
    FOREACH(rooms_t, r_linked, i, room->links)
        //my_printf("check r %s, occupied %i, proceed %i\n", r_linked->name, r_linked->occupied, r_linked->is_proceeded);
        if (r_linked->is_proceeded || r_linked->type == START) {
          //  my_printf("skip\n");
            CONTINUE(i);
        }
        r_linked->is_proceeded = true;
       // my_printf("proceed room link %s\n", r_linked->name);
        tmp = proceed_room(r_linked, room);
     //   my_printf("got room %s ret from %s score tmp: %i best score : %i\n", tmp->name, r_linked->name, tmp->score, best_room ? best_room->score : 999);
        r_linked->is_proceeded = false;
        r_linked->score += tmp->score;
        if (!best_room || tmp->score < best_room->score)
            best_room = r_linked;
    ENDFOREACH(i, room->links)
    if (!best_room) {
        best_room = room;
        best_room->score = 999999999;
    }
   // my_printf("Best room score: %i\n", best_room->score);
    return (best_room);
}

rooms_t *get_best_room(ant_t *ant)
{
    if (!ant)
        return (NULL);
    //my_printf("\n\nfor ant %i\n", ant->id);
    return (proceed_room(ant->current_room, ant->old_room));
}