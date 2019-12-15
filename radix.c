/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** [Pushswap - Radix Algo File]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/simple_linked_list.h"
#include "include/double_circular_linked_list.h"
#include "include/my.h"
#include "include/my_list.h"

void pb_function(linked_list_t **head_a, linked_list_b **head_b, char *value)
{
    if ((*head_a) == (*head_a)->next)
        (*head_a) = NULL;
    else {
        (*head_a) = (*head_a)->next;
        (*head_a)->prev = (*head_a)->prev->prev;
        (*head_a)->prev->next = (*head_a);
    }
    insertBeginSimple(head_b, value);
    write(1, "pb ", 3);
}

void pa_function(linked_list_t **head_a, linked_list_b **head_b, char *value)
{
    insertBegin(head_a, value);
    deleteFirstNodeSimple(head_b);
    write(1, "pa ", 3);
}

void radix_lsb(linked_list_t **head_a, linked_list_b **head_b)
{
    int mask = 0;
    int save = count_list(*head_a);

    for (int i = 0 ; i < 32 ; i++) {
        int m = save;
        while (m != 0) {
            mask = pow(2, i);
            if (((*head_a)->data >> i & 1)) {
                ra_function(head_a);
                m--;
            }
            else {
                pb_function(&(*head_a), &(*head_b), (*head_a)->value);
                m--;
            }
        }
        for (int n = count_simple_list(*head_b) ; n != 0 ; n--)
            pa_function(head_a, head_b, (*head_b)->value);
    }
}
