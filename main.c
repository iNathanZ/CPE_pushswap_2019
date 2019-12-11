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

void ra(linked_list_t **head)
{
    if (*head == NULL)
        return;
    *head = (*head)->prev;
    write(1, "ra ", 3);
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

void insertBeginSimple(linked_list_b **head, char *value)
{
    linked_list_b *new_node = malloc(sizeof(linked_list_b));

    new_node->value = value;
    new_node->data = my_getnbr(value);
    new_node->next = (*head);
    (*head) = new_node;
}

void pb(linked_list_t **head_a, linked_list_b **head_b, char *value)
{
    (*head_a) = (*head_a)->next;
    (*head_a)->prev = (*head_a)->prev->prev;
    (*head_a)->prev->next = (*head_a);
    insertBeginSimple(head_b, value);
}

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

void print_simple_list(linked_list_t *head)
{
    while (head) {
        my_put_nbr(head->data);
        my_putchar(' ');
        head = head->next;
    }
    my_putchar('\n');
}


int main(int argc, char**argv)
{
    int size = 0;
    int args = argc - 1;
    linked_list_t *head_a = NULL;
    linked_list_b *head_b = NULL;

    for (int i = 1; i <= args ; i++) {
        push_list(&head_a, argv[i]);
    }
    pb(&head_a, &head_b, argv[1]);
    my_putstr("list_a : \n");
    print_list(head_a);
    my_putstr("list_b : \n");
    print_simple_list(head_b);

}
