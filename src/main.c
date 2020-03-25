/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "lemin.h"
#include "my.h"

int main(void)
{
    lemin_t *lemin = get_lemin();
    ant_t *ants = NULL;
    rooms_t *end_room = NULL;

    if (!lemin)
        return (ERROR);
    ants = get_ants(lemin);
    end_room = get_end_room(lemin);
    if (!ants || !end_room)
        return (ERROR);
    my_printf("#moves\n");
    while (play_a_turn(ants, end_room));
    return (0);
}
