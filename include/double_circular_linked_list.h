/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** [double_circular_linked_list.c]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_list.h"
#include "my.h"

void push_list(linked_list_t **head, char *value);
void ra(linked_list_t **head);
void insertBegin(linked_list_t** head, char *value);
void print_list(linked_list_t *head);
int count_list(linked_list_t *head);
