/*
** EPITECH PROJECT, 2020
** str_to_arg.C
** File description:
** str_to_arg
*/

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