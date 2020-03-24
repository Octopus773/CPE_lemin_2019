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
    str = &str[1];
    room->y = my_getnbr(str);
    print_room(room);
}

int set_room(lemin_t *infos, char *str, char type)
{
    rooms_t *room = malloc(sizeof(rooms_t));
    int len = word_len(str, ' ');

    if (!room)
        return (ERROR_MALLOC);
    room->name = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++) {
        room->name[i] = *str;
        str = &str[1];
    }
    room->name[len] = 0;
    room->type = type;
    room->occupied = false;
    room->score = 0;
    room->is_proceeded = false;
    room_set_coord(room, str);
    FOREACH(rooms_t, tmp, i, infos->map)
        if (my_strcmp(tmp->name, room->name) == 0
        || (tmp->x == room->x && tmp->y == room->y))
            return (ERROR_FORMAT);
    ENDFOREACH(i, infos->map)
    lily_add_node(&infos->map, lily_create_node(room), 0);
    return (0);
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
    int type;
    char *str = NULL;
    size_t nb = 0;
    int nb_tunnels = 0;

    while (getline(&str, &nb, stdin) > 1) {
        nb = 0;
        type = get_type(str);
        if (type == 0) {
            free(str);
            return (ERROR_FORMAT);
        }
        if (type == COMMENT && my_strcmp(str, "##start") == 0) {
            if (getline(&str, &nb, stdin) <= 0) {
                free(str);
                return (ERROR_FORMAT);
            }
            my_putstr("##start\n");
            set_room(infos, str, START);
            nb = 0;
        }
        else if (type == COMMENT && my_strcmp(str, "##end") == 0) {
            if (getline(&str, &nb, stdin) <= 0) {
                free(str);
                return (ERROR_FORMAT);
            }
            my_putstr("##end\n");
            set_room(infos, str, END);
            nb = 0;
        }
        if (type == ROOM)
            if (set_room(infos, str, ROOM) == ERROR_FORMAT)
                return (ERROR_FORMAT);
        if (type == LINK) {
            if (nb_tunnels == 0)
                my_putstr("#tunnels\n");
            if (set_links(infos, str) == ERROR_FORMAT) {
                free(str);
                return (ERROR_FORMAT);
            }
            nb_tunnels = 1;
        }
    }
    return (0);
}