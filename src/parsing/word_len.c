/*
** EPITECH PROJECT, 2020
** str_to_arg.C
** File description:
** str_to_arg
*/

int word_len(char *str, char s)
{
    int le = 0;

    if (str[0] == '\"') {
        le++;
        while (str[le] && str[le] != '\"')
            le++;
        return (le - 1);
    }
    for (; str[le] && str[le] != s && str[le] != ' ' && str[le] != 9; le++);
    return (le);
}