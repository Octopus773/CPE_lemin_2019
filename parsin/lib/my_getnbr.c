/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** returns number given in params
*/

int my_getnbr(char const *str)
{
    long nbr = 0;
    int is_neg = 0;

    for (int n = 0; str[n]; n++) {
        if (str[n] == '+')
            nbr = nbr;
        if (str[n] == '-')
            is_neg++;
        if (str[n] >= '0' && str[n] <= '9')
            nbr = nbr * 10 + (str[n] - '0');
        if (!(str[n] >= '0' && str[n] <= '9')
        && str[n] != '+' && str[n] != '-')
            break;
    }
    if (is_neg % 2 == 1)
        nbr *= -1;
    if (nbr > 2147483647 || nbr < -2147483648)
        nbr = 0;
    return ((int)nbr);
}
