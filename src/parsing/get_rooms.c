/*
** EPITECH PROJECT, 2020
** get_rooms.c
** File description:
** get_rooms
*/

#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int set_links(lemin_t *infos, char *str);

int set_room(lemin_t *infos, char *str, char type);

void print_room(rooms_t *room)
{
    my_putstr(room->name);
    my_putchar(' ');
    my_put_nbr(room->x);
    my_putchar(' ');
    my_put_nbr(room->y);
    my_putchar('\n');
}

void room_set_coord(rooms_t *room, char *str)
{
    room->x = my_getnbr(str);
    for (; *str && *str != ' '; str = &str[1]);
    if (str)
        str = &str[1];
    room->y = my_getnbr(str);
    print_room(room);
}

int get_type(char *str)
{
    int nb_spaces = 0;
    int nb_dash = 0;

    if (str[0] == '#')
        return (COMMENT);
    for (int i = 0; str[i] && str[i + 1] != '#' && str[i] != '\n'; i++) {
        if (str[i] == ' ')
            nb_spaces++;
        if (str[i] == '-')
            nb_dash++;
    }
    if (nb_spaces == 2)
        return (ROOM);
    if (nb_dash == 1 && str[0] != '-')
        return (LINK);
    return (0);
}

int get_rooms(lemin_t *infos)
{
    char *str = NULL;
    size_t nb = 0;
    int nb_tunnels = 0;

    while (getline(&str, &nb, stdin) > 1) {
        if (read_loop(str, &nb_tunnels, infos)) {
            nb_tunnels = 0;
            break;
        }
    }
    free(str);
    if (nb_tunnels != 3)
        return (ERROR);
    return (0);
}