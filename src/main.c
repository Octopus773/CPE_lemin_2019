/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "lemin.h"

int main(void)
{
    lemin_t *t = get_lemin();
    rooms_t *tmp = t->map;
    printf("##nb ant\n%d\n\n", t->nb_ant);
    for(; tmp; tmp = tmp->next) {
        printf("##name: %s\n", tmp->name);
        printf("##cord: %d %d\n", tmp->x, tmp->y);
        printf("##type (1: START, 2: END, 3: ROOM): %d\n", tmp->type);
        printf("##connections\n");
        for (connections_t *a = tmp->links; a; a = a->next)
            printf("\t%s\n", a->name);
    }
}
