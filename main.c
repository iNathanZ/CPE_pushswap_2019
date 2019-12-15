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

int check_list_sorted(linked_list_t *head)
{
    for (linked_list_t *tmp = head; tmp->next != head ; tmp = tmp->next) {
        if (tmp->data >= tmp->next->data) {
            return (0);
        }
    }
    return (1);
}

int check_list_neg(linked_list_t *head)
{
    for (linked_list_t *tmp = head; tmp->next != head ; tmp = tmp->next) {
        if (tmp->data < 0 || tmp->next->data < 0) {
            return (0);
        }
    }
    return (1);
}

void neg_sort(linked_list_t *head_a)
{
    while (head_a->data >= 0)
        ra(&head_a);
}

int main(int argc, char **argv)
{
    int args = argc - 1;
    int n = 0;
    linked_list_t *head_a = NULL;
    linked_list_b *head_b = NULL;

    for (int i = 1; i <= args ; i++)
        push_list(&head_a, argv[i]);
    n = check_list_sorted(head_a);
    if (n == 1 || argc <= 1) {
        my_putchar('\n');
        return (84);
    }
    n = check_list_neg(head_a);
    radix_lsb(&head_a, &head_b);
    if (n == 0)
        neg_sort(head_a);
    write (1, "sa sa\n", 6);
    return (0);
}
