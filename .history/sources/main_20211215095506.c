/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

/*void func_rra(t_node *l_a)
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
    printf("rr ");
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
    printf("pa ");
}
// Hasta aqui en el functions1.c
void func_pb(t_node **l_a, t_node **l_b, t_variables *var)
{
    t_node *tmp_a = *l_a;
    t_node *b_final = malloc(sizeof(t_node));

    b_final->data = (*l_a)->data;
    b_final->nextPtr = (*l_b);
    var->count_lb++;
    var->count_la--;
    *l_b = b_final;
    *l_a = tmp_a->nextPtr;
    printf("pb ");
}

void func_sa(t_node *l_a, t_variables *var)
{
    int valuetmp;
    t_node *tmp = l_a;

    if (var->count_la >= 2) { 
        valuetmp = tmp->data;
        tmp->data = tmp->nextPtr->data;
        tmp->nextPtr->data = valuetmp;
    }
    else
        printf("Not enough arguments in l_a\n");
    printf("sa ");
}

void func_sb(t_node *l_b, t_variables *var) 
{
    int valuetmp;
    t_node *tmp = l_b;

    if (var->count_lb >= 2) {
        valuetmp = tmp->data;
        tmp->data = tmp->nextPtr->data;
        tmp->nextPtr->data = valuetmp;
    }
    else
        printf("Not enough arguments in l_b\n");
    printf("sb ");
}

void func_sc(t_node *l_a, t_node *l_b, t_variables *var)
{
    func_sa(l_a, var);
    func_sb(l_b, var);
    printf("sc ");
}

void printlinked(t_node *file)
{
    t_node *tmp = file;
    //tmp = tmp->nextPtr;
    while (tmp != NULL) {
        printf("%d ",tmp->data);
        tmp = tmp->nextPtr;
    }
    printf("\n");
}
// Hasta aqui en el function2.
int check_sorted(t_variables *var, t_node *l_a)
{
    int i = 1;
    t_node *tmp = l_a;

    while (tmp->nextPtr != NULL && (tmp->data) <= (tmp->nextPtr->data)) {
        tmp = tmp->nextPtr;
        i++;
    }

void errornumber_elements(t_variables *var)
{
    if (var->argc < 2)
        exit (84);
    if (var->argc == 2) {
        printf("%s",var->argv[1]);
        exit (1);
    }
}

void error_manager(t_variables *var)
{
    errornumber_elements(var);
}

int main(int argc, char **argv)
{
    t_node *l_a = malloc(sizeof(t_node *));
    t_node *l_b = malloc(sizeof(t_node *));
    t_variables var;

    var.count_la = (argc - 1);
    var.count_lb = 0;
    var.argc = argc;
    var.argv = argv;

    error_manager(&var);
    save(argc, argv, l_a);
    l_a = l_a->nextPtr;
    l_b = l_b->nextPtr;
    if(check_sorted(&var, l_a))
        printf("SORTED");
    while (check_sorted(&var, l_a) != 1 && var.count_la > 1) {
        algorithm_sort(&l_a, &l_b, &var);
    }
    algorithm_sort2(&l_a, &l_b, &var);
    printf("\n");
    printlinked(l_a);
    printlinked(l_b);
    if(check_sorted(&var, l_a))
        printf("SORTED");
    free_node(l_a, l_b);
    return (0);
}