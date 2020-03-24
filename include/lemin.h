/*
** EPITECH PROJECT, 2020
** lemin.h
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#define COMMENT         (7)
#define LINK            (6)

#define ERROR_READ      (4)
#define ERROR_FORMAT    (5)
#define ERROR_MALLOC    (84)

#define START           (1)
#define END             (2)
#define ROOM            (3)

typedef struct s_connections {
    char *name;
    struct s_connections *next;
} connections_t;

typedef struct s_rooms{
    char type;
    char *name;
    unsigned int x;
    unsigned int y;
    connections_t *links;
    struct s_rooms *next;
}rooms_t;


typedef struct s_lemin
{
    unsigned int nb_ant;
    rooms_t *map;
}lemin_t;

int word_len(char *str, char s);
int get_nb_ants(lemin_t *infos);
int set_links(lemin_t *infos, char *str);
int get_rooms(lemin_t *infos);
lemin_t *get_lemin(void);

#endif /* !LEMIN_H_ */
