/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** [simple_linked_list.c]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_list.h"
#include "my.h"

void push_simple_list(linked_list_b **head, linked_list_b *elem);
linked_list_b *node_create(char *value);
void insertBeginSimple(linked_list_b **head, char *value);
void deleteFirstNodeSimple(linked_list_b **head);
int count_simple_list(linked_list_b *head);
