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
    lemin_t *t = get_lemin();
    rooms_t *tmp = t->map;
    
    my_printf("##nb ant\n%d\n\n", t->nb_ant);
    for(; tmp; tmp = tmp->next) {
        my_printf("##name: %s\n", tmp->name);
        my_printf("##cord: %d %d\n", tmp->x, tmp->y);
        my_printf("##type (1: START, 2: END, 3: ROOM): %d\n", tmp->type);
        my_printf("##connections\n");
        for (connections_t *a = tmp->links; a; a = a->next)
            my_printf("\t%s\n", a->name);
    }
}
