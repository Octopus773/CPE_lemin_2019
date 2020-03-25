/*
** EPITECH PROJECT, 2020
** links.C
** File description:
** links
*/

#include "lemin.h"
#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char *get_first_link(char *str)
{
    char *result = NULL;
    int len = word_len(str, '-');

    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    for (int i = 0; i < len; i++)
        result[i] = str[i];
    result[len] = 0;
    return (result);
}

char *get_second_link(char *str)
{
    char *result = NULL;
    int len = 0;

    while (*str && *str != '-')
        str = &str[1];
    str = &str[1];
    len = word_len(str, '\n');
    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    for (int i = 0; i < len; i++)
        result[i] = str[i];
    result[len] = 0;
    return (result);

}

rooms_t *find_node(lemin_t *infos, char *str)
{
    FOREACH(rooms_t, room, i, infos->map)
        if (my_strcmp(room->name, str) == 0)
            return (room);
    ENDFOREACH(i, infos->map)
    return (NULL);
}

int create_link(char *first, char *second, lemin_t *infos)
{
    rooms_t *tmp = find_node(infos, first);
    rooms_t *link_to = find_node(infos, second);

    if (!tmp || !link_to)
        return (ERROR_FORMAT);
    lily_add_node(&tmp->links, lily_create_node(link_to), 0);
    return (0);
}

int set_links(lemin_t *infos, char *str)
{
    char *first = get_first_link(str);
    char *second = get_second_link(str);

    if (!first)
        return (ERROR_MALLOC);
    if (create_link(first, second, infos) == ERROR_FORMAT)
        return (ERROR_FORMAT);
    create_link(second, first, infos);
    free(first);
    free(second);
    write(1, str, word_len(str, '\n'));
    my_putchar('\n');
    return (0);
}
