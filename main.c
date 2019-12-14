/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** [Main File Pushswap]
*/

#include "include/radix.h"
#include "include/double_circular_linked_list.h"
#include "include/simple_linked_list.h"
#include "include/my.h"
#include "include/my_list.h"

int check(char *first, char *second)
{
    if (my_getnbr(first) <= my_getnbr(second)) {
        return (1);
    }
    else {
        return (0);
    }
}

int main(int argc, char **argv)
{
    int args = argc - 1;
    int n = 0;
    linked_list_t *head_a = NULL;
    linked_list_b *head_b = NULL;

    if (argc <= 1) {
        my_putchar('\n');
        return (84);
    }
    for (int i = 1 ; i <= argc - 2 ; i++)
        n = check(argv[i], argv[i + 1]);
    if (n == 1) {
        my_putchar('\n');
        return (0);
    }
    for (int i = 1; i <= args ; i++)
        push_list(&head_a, argv[i]);
    radix_lsb(&head_a, &head_b);
    my_putchar('\n');
    return (0);
}
