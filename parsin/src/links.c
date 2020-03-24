/*
** EPITECH PROJECT, 2020
** links.C
** File description:
** links
*/

#include "lemin.h"
#include "my.h"
#include <stdlib.h>

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

rooms_t *find_node(rooms_t *rooms, char *str)
{
    for (; rooms; rooms = rooms->next) {
        if (my_strcmp(rooms->name, str) == 0)
            return (rooms);
    }
    return (rooms);
}

int create_link(char *first, char *second, lemin_t *infos)
{
    rooms_t *tmp = find_node(infos->map, first);
    rooms_t *link_to = find_node(infos->map, second);
    connections_t *link = NULL;

    if (!tmp || !link_to)
        return (ERROR_FORMAT);
    link = malloc(sizeof(connections_t));
    if (!link)
        return (ERROR_MALLOC);
    link->name = link_to->name;
    link->next = tmp->links;
    tmp->links = link;
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
    my_putstr(str);
    return (0);
}
