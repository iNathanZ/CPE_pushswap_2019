/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** my_list.h file
*/

#ifndef list_h
#define list_h

typedef struct linked_list_a
{
    char *value;
    int data;
    struct linked_list_a *next;
    struct linked_list_a *prev;
} linked_list_t;

typedef struct linked_list
{
    char *value;
    int data;
    struct linked_list *next;
} linked_list_b;

#endif
