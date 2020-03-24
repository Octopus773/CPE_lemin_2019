/*
** EPITECH PROJECT, 2020
** str_to_arg.C
** File description:
** str_to_arg
*/
#include <stdlib.h>

int count_word(char *str, char c);

int is_not_a_letter(char c, char s);

void move_ptr(char *str, int *nb, int *i);

int word_len(char *str, char s);

char **str_to_word_array(char *str, char s)
{
    char *tmp = str;
    int nb_arg = count_word(str, s);
    char **argv = malloc(sizeof(char *) * (nb_arg + 1));
    int len;

    for (int i = 0; i < nb_arg; i++) {
        while (is_not_a_letter(*tmp, s) && *tmp != '\"')
            tmp = &tmp[1];
        len = word_len(tmp, s);
        argv[i] = malloc(sizeof(char) * (len + 1));
        if (*tmp == '\"')
            tmp = &tmp[1];
        for (int c = 0; c < len; c++)
            argv[i][c] = tmp[c];
        argv[i][len] = 0;
        for (int k = 0; k < len; k++)
            tmp = &tmp[1];
        if (str[i] == '\"')
            tmp = &tmp[1];
    }
    argv[nb_arg] = NULL;
    return (argv);
}

int is_not_a_letter(char c, char s)
{
    if (c == s)
        return (1);
    if (c == ' ')
        return (1);
    if (c == 9)
        return (1);
    if (c == 0)
        return (1);
    return (0);
}

int word_len(char *str, char s)
{
    int l = 0;

    if (str[0] == '\"') {
        l++;
        while (str[l] && str[l] != '\"')
            l++;
        return (l - 1);
    }
    for (; str[l] && str[l] != s && str[l] != ' ' && str[l] != 9; l++);
    return (l);
}

int count_word(char *str, char c)
{
    int i = 0;
    int nb = 0;

    while (str[i]) {
        if (str[i] == '\"') {
            move_ptr(str, &nb, &i);
            continue;
        }
        if ((str[i] != ' ' && str[i] != c) && str[i] != 9)
            nb++;
        while (((str[i] != ' ' && str[i] != c) && str[i] != 9) && str[i])
            i++;
        while (((str[i] == ' ' || str[i] == c) || str[i] == 9) && str[i])
            i++;
    }
    return nb;
}

void move_ptr(char *str, int *nb, int *i)
{
    (*nb)++;
    (*i)++;
    for (; str[*i] && str[*i] != '\"'; (*i)++);
    if (str[*i] == '\"')
        (*i)++;
}