/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** task06 day06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int letter = 0;

    while (s1[letter]) {
        if (s2[letter] == '\0')
            return (0);
        if (s1[letter] > s2[letter])
            return (1);
        else if (s1[letter] < s2[letter])
            return (-1);
        letter++;
    }
    return (0);
}

