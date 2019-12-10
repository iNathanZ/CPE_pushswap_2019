/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** [Main File Pushswap]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "my_list.h"

void push_list(linked_list_t **head, char *value)
{
    if (*head == NULL) {
        linked_list_t *new_node = malloc(sizeof(linked_list_t));
        new_node->value = value;
        new_node->data = my_getnbr(value);
        new_node->next = new_node->prev = new_node;
        *head = new_node;
        return;
    }
    linked_list_t *last = (*head)->prev;
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    new_node->value = value,
    new_node->data = my_getnbr(value);
    new_node->next = *head;
    (*head)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
    return;
}

void print_list(linked_list_t *head)
{
    linked_list_t *temp = head;

    while (temp->next != head) {
        my_put_nbr(tempé->data);
        my_putchar(' ');
        temp = temp->next;
    }
    my_put_nbr(temp->data);
    my_putchar(' ');
}

int main(int argc, char**argv)
{
    int size = 0;
    int args = argc - 1;
    linked_list_t *head_a = NULL;
    linked_list_t *head_b = NULL;

    for (int i = 1; i <= args ; i++) {
        push_list(&head_a, argv[i]);
    }
    my_putstr("list_a : \n");
    print_list(head_a);
}
