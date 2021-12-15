/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

// Hasta aqui en algorithm.c
void errornumber_elements(t_variables *var)
{
    if (var->argc < 2 || var->argc == 2)
        exit (84);
}

void error_manager(t_variables *var)
{
    errornumber_elements(var);
}

void push_swap(t_variables *var)
{
    t_node *l_a = malloc(sizeof(t_node *));
    t_node *l_b = malloc(sizeof(t_node *));

    error_manager(&var);
    save(var->argc, var->argv, l_a);
    l_a = l_a->nextPtr;
    l_b = l_b->nextPtr;
    while (check_sorted(&var, l_a) != 1 && var->count_la > 1) {
        algorithm_sort(&l_a, &l_b, &var);
    }
    algorithm_sort2(&l_a, &l_b, &var);
    printf("\n");
    free_node(l_a, l_b);
}

int main(int argc, char **argv)
{
    t_variables var;

    var.count_la = (argc - 1);
    var.count_lb = 0;
    var.argc = argc;
    var.argv = argv;

    return (0);
}