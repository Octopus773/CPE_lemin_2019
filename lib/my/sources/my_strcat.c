/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** task02 day07
*/

char *my_strcat(char *dest, char const *src)
{
    int memo = 0;

    for (int i = 0; dest[i] != '\0'; i++) {
        memo = i;
    }
    if (memo != 0)
        memo++;
    for (int b = 0; src[b] != '\0'; b++) {
        dest[memo] = src[b];
        memo++;
    }

    dest[memo] = '\0';
    return (dest);
}
