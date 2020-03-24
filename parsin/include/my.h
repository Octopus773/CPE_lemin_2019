/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contains library prototypes
*/

#include <stdlib.h>

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_puterr(char const *str);
int my_strlen(char const *str);
int my_swap(int *a, int *b);
void my_sort_int_array(int *array, int size);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int alpha_numeric(char c);
int longest_word(char const *str);
int how_many(char const *str);
char **my_str_to_word_array(char const *str);
int string_length(char *str);
void convert_to_lowcase_hex(int number_to_convert);
int my_is_it_prime(int nb);
char *my_strdup(char const *src);
int my_getnbr_base(char const *str, char const *base);
int my_show_word_array(char const *tab);
int my_putnbr_base(int nbr, char const *base);
int is_it_sorted(int *array, int size);
char **str_to_word_array(char *str, char s);
int is_not_a_letter(char c, char s);
int word_len(char *str, char s);
int count_word(char *str, char c);
void move_ptr(char *str, int *nb, int *i);
char *int_to_str(int nb);
int my_atoi(char **buff);
char *my_newstrcat(char *dst, char *src, char sep);