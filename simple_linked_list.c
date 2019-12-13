/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** [Pushswap - Simple Linked List File]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/my_list.h"

void push_simple_list(linked_list_b **head, linked_list_b *elem)
{
    if (*head == NULL) {
        *head = elem;
        return;
    }

    linked_list_b *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = elem;
    return;
}

linked_list_b *node_create(char *value)
{
    linked_list_b *node = malloc(sizeof(linked_list_b));

    node->value = value;
    node->data = my_getnbr(value);
    node->next = NULL;
    return (node);
}

void insertBeginSimple(linked_list_b **head, char *value)
{
    linked_list_b *new_node = malloc(sizeof(linked_list_b));

    new_node->value = value;
    new_node->data = my_getnbr(value);
    new_node->next = (*head);
    (*head) = new_node;
}

void deleteFirstNodeSimple(linked_list_b **head)
{
    linked_list_b *tmp = *head;

    if (*head == NULL)
        return;
    *head = tmp->next;
    free(tmp);
    return;
}

int count_simple_list(linked_list_b *head)
{
    int n = 0;
    while (head) {
        n++;
        head = head->next;
    }
    return (n);
}
