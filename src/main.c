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
    if (!lemin)
        return (ERROR);
    ant_t *ants = get_ants(lemin);
    rooms_t *end_room = get_end_room(lemin);

    if (!lemin || !ants || ! end_room)
        return (ERROR);
    my_printf("#moves\n");
    while (play_a_turn(ants, end_room));
    return (0);
}
