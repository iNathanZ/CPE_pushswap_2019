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


int main(int argc, char**argv)
{
    int size = 0;
    int args = argc - 1;
    linked_list_t *head_a = NULL;
    linked_list_b *head_b = NULL;

    if (argc <= 1)
        return (84);
    for (int i = 1; i <= args ; i++) {
        push_list(&head_a, argv[i]);
    }
    radix_lsb(&head_a, &head_b);
    return (1);
}
