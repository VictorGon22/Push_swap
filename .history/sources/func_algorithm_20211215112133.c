/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
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

void finc_closer2(t_variables *var, t_node **l_a, t_node **l_b)
{

}

void find_closer(t_variables *var, t_node **l_a, t_node **l_b)
{
    var->pos_to_move = 0;
    var->tmp_small = var->pos_smaller;
    var->tmp_big = var->pos_bigger;

    var->side1 = 0;
    var->side2 = 0;
    if ((var->count_la / 2) < var->pos_smaller) {
        var->tmp_small = var->count_la - var->pos_smaller;
        var->side1 = 1;
    }
    if ((var->count_la / 2) < var->pos_bigger) {
        var->tmp_big = var->count_la - var->pos_bigger;
        var->side2 = 1;
    }
    // f
    if (var->tmp_big <= var->tmp_small) {
        var->side = var->side2;
        var->pos_to_move = var->tmp_big;
    } else if (var->tmp_big > var->tmp_small) {
        var->side = var->side1;
        var->pos_to_move = var->tmp_small;
    }
    //
    if (var->side == 1) {
        while (pos_to_move > 0) {
            func_rra(*l_a);
            pos_to_move--;
        }
    } else if (var->side == 0) {
        while (pos_to_move > 0) {
            func_ra(*l_a);
            pos_to_move--;
        }
    }
    func_pb(l_a, l_b, var);
    var->side = 0;
}

void algorithm_sort(t_node **l_a, t_node **l_b, t_variables *var)
{
    int pos = 0;
    t_node *tmp_a = *l_a;

    var->smaller = (*l_a)->data;
    var->bigger = (*l_a)->data;
    var->pos_smaller = 0;
    var->pos_bigger = 0;
    while (tmp_a != NULL) {
        if (tmp_a->data < var->smaller) {
            var->smaller = tmp_a->data;
            var->pos_smaller = pos;
        }
        if (tmp_a->data > var->bigger){
            var->bigger = tmp_a->data;
            var->pos_bigger = pos;
        }
        pos++;
        tmp_a = tmp_a->nextPtr;
    }
    find_closer(var, l_a, l_b);
}

void algorithm_sort2(t_node **l_a, t_node **l_b, t_variables *var)
{
    int pos = 0;
    t_node *tmp_a = *l_a;

    var->smaller = (*l_a)->data;
    var->bigger = (*l_a)->data;
    var->pos_smaller = 0;
    var->pos_bigger = 0;
    while (var->count_lb != 0) {
        func_pa(l_a, l_b, var);
        if ((*l_a)->data > (*l_a)->nextPtr->data)
            func_ra(*l_a);
    }
}
