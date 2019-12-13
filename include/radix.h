/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** [radix.c]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_list.h"
#include "my.h"

void pb(linked_list_t **head_a, linked_list_b **head_b, char *value);
void pa(linked_list_t **head_a, linked_list_b **head_b, char *value);
void radix_lsb(linked_list_t **head_a, linked_list_b **head_b);
