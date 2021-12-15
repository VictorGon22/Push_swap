/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void func_rra(t_node *l_a)
{
    int data;
    int next;
    t_node *tmp = l_a;

    data = tmp->data;
    while (tmp->nextPtr != NULL) {
        tmp = tmp->nextPtr;
        next = tmp->data;
        tmp->data = data;
        data = next;
    }
    tmp = l_a;
    tmp->data = data;
    printf("rra ");
}

void func_rrr(t_node *l_a, t_node *l_b)
{
    func_rra(l_a);
    func_rra(l_b);
    printf("rrr ");
}

void func_ra(t_node *l_a)
{
    int data;
    int next;
    t_node *tmp = l_a;
   
    data = tmp->data;
    while (tmp->nextPtr != NULL) {
        next = tmp->nextPtr->data;
        tmp->data = next;
        tmp = tmp->nextPtr;
    }
    tmp->data = data;
    printf("ra ");
}

void func_rr(t_node *l_a, t_node *l_b)
{
    func_ra(l_a);
    func_ra(l_b);
    my_putstr("rr ");
}

void func_pa(t_node **l_a, t_node **l_b, t_variables *var)
{
    t_node *tmp_b = *l_b;
    t_node *a_final = malloc(sizeof(t_node));

    a_final->data = (*l_b)->data;
    a_final->nextPtr = (*l_a);
    var->count_la++;
    var->count_lb--;
    *l_a = a_final;
    *l_b = tmp_b->nextPtr;
    my_putstr("pa ");
}
