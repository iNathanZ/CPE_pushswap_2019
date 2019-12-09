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

void push_list(linked_list_t **head, linked_list_t *elem)
{
    if (*head == NULL) {
        *head = elem;
        return;
    }

    linked_list_t *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = elem;
    return;
}

linked_list_t *node_create(char *value)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    node->value = value;
    node->data = my_getnbr(value);
    node->next = NULL;
    return (node);
}

void sa(linked_list_t **head)
{
    char *temp = (*head)->value;
    (*head)->value = (*head)->next->value;
    (*head)->next->value = temp;
    return;
}

void sb(linked_list_t **head)
{
    char *temp = (*head)->value;
    (*head)->value = (*head)->next->value;
    (*head)->next->value = temp;
    return;
}

void ra(linked_list_t **head)
{
    if (!*head || !(*head)->next)
        return;
    linked_list_t **pp = &(*head)->next;
    while (*pp && (*pp)->next)
        pp = &(*pp)->next;
    linked_list_t *tmp = *head;
    *head = *pp;
    *pp = tmp;
    (*head)->next = (*pp)->next;
    (*pp)->next = NULL;
    return;
}

void rb(linked_list_t **head)
{
    if (!*head || !(*head)->next)
        return;
    linked_list_t **pp = &(*head)->next;
    while (*pp && (*pp)->next)
        pp = &(*pp)->next;
    linked_list_t *tmp = *head;
    *head = *pp;
    *pp = tmp;
    (*head)->next = (*pp)->next;
    (*pp)->next = NULL;
    return;
}

void print_list(linked_list_t *head)
{
    while (head) {
        my_put_nbr(head->data);
        my_putchar(' ');
        head = head->next;
    }
    my_putchar('\n');
}

void mask_list(linked_list_t *head)
{
    while (head != NULL) {
        int mask = 0;
        for (int i = 0; i < 32; i++) {
            mask = pow(2, i);
            my_put_nbr((head->data & mask) != 0);
        }
        head = head->next;
        my_putchar('\n');
    }
}

int main(int argc, char**argv)
{
    int size = 0;
    int args = argc - 1;
    linked_list_t *head = NULL;
    for (int i = 1; i <= args ; i++) {
        push_list(&head, node_create(argv[i]));
    }
    print_list(head);
    printf("\n\nMasques :\n");
    mask_list(head);

}
