/*
** EPITECH PROJECT, 2020
** lemin.h
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#define ERROR 84

#define COMMENT (7)
#define LINK (6)

#define ERROR_READ (4)
#define ERROR_FORMAT (5)
#define ERROR_MALLOC (84)

#define START (1)
#define END (2)
#define ROOM (3)

#include "lily.h"

typedef struct s_rooms{
    char type;
    char *name;
    unsigned int x;
    unsigned int y;
    lily_list *links;
}rooms_t;


typedef struct s_lemin
{
    unsigned int nb_ant;
    lily_list *map;
}lemin_t;

typedef struct s_ant
{
    int id;
    lily_list *current_room;
    lily_list *old_room;
} ant_t;

int word_len(char *str, char s);
int get_nb_ants(lemin_t *infos);
int set_links(lemin_t *infos, char *str);
lemin_t *get_lemin(void);
ant_t *get_ants(lemin_t *lemin);
bool play_a_turn(ant_t *ants, lily_list *end_room);

lily_list *get_start_room(lemin_t *lemin);
lily_list *get_end_room(lemin_t *lemin);
int get_rooms(lemin_t *infos);

#endif /* !LEMIN_H_ */
