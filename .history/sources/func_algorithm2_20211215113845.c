/*
** EPITECH PROJECT, 2021
** function main
** File description:
** algo
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

int find_biggest_nbr(t_node *l_a)
{
    t_node *tmp_a = l_a;
    int biggestnumber = tmp_a->data;

    while (tmp_a != NULL) {
        if (biggestnumber < tmp_a->data)
            biggestnumber = tmp_a->data;
        tmp_a = tmp_a->nextPtr;
    }
    return (biggestnumber);
}

int get_last_value(t_node *l_a)
{
    t_node *tmp_a = l_a;

    while (tmp_a->nextPtr != NULL) {
        tmp_a = tmp_a->nextPtr;
    }
    return (tmp_a->data);
}
