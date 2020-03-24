/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** task05 day06
*/

static int my_strlen_strstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strstr(char *str, char const *to_find)
{
    int size = my_strlen_strstr(to_find);

    for (int i = 0; str[i]; i++) {
        for (int j = 0; str[i + j] == to_find[j]; j++) {
            if (j == size - 1)
                return (&str[i]);
        }
    }
    return (0);
}
