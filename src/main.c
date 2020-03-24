/*
** EPITECH PROJECT, 2019
** task1 day13
** File description:
** none
*/

#include "my.h"
#include "lily.h"

void print_ls(lily_list *first)
{
    lily_list *start_node = first->prev;

    while (first != start_node) {
        my_putstr(first->data);
        my_putchar('\n');
        first = first->next;
    }
    my_putstr(first->data);
    my_putchar('\n');
}


int main(int ac, char **av)
{
    (void)ac;
    lily_list *first = lily_create_list_from_array((void **)av);
    void *cmp_ptr = &my_strcmp;
    lily_sort_list_az(&first, cmp_ptr);
    print_ls(first);
}