/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** [Pushswap - Double Circular Linked List File]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/my_list.h"

void print_list(linked_list_t *head)
{
    linked_list_t *temp = head;

    while (temp->next != head) {
        my_put_nbr(temp->data);
        my_putchar(' ');
        temp = temp->next;
    }
    my_put_nbr(temp->data);
    my_putchar('\n');
}

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

void ra(linked_list_t **head)
{
    linked_list_t *new_node = (*head);
    if (*head == NULL)
        return;
    (*head) = (*head)->next;
    (*head)->prev->prev->next = (*head);
    (*head)->prev = new_node->prev;
    push_list(head, new_node->value);
    write(1, "ra ", 3);
    return;
}

void insertBegin(linked_list_t** head, char *value)
{
    linked_list_t *last = (*head)->prev;
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    new_node->value = value;
    new_node->data = my_getnbr(value);
    new_node->next = *head;
    new_node->prev = last;
    last->next = (*head)->prev = new_node;
    *head = new_node;
}

int count_list(linked_list_t *head)
{
    linked_list_t *temp = head;
    int n = 0;

    while (temp->next != head) {
        n++;
        temp = temp->next;
    }
    n++;
    return (n);
}
