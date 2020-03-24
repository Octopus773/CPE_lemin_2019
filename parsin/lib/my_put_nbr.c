/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** displays nb given as parameter
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb > 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return (0);
}

