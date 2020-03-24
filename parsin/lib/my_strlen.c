/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** returns number of character in a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
