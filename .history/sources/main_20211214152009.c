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
   
    data = tmp->data; // Valor que possarem al final de la linked 
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
    printf("pa ");
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
    while (tmp != NULL) {
        printf("%d ",tmp->data);
        tmp = tmp->nextPtr;
    }
    printf("\n");
}

int check_sorted(int argc, t_node *l_a)
{
    t_node *tmp = l_a;
    int i = 0;
    while (tmp->nextPtr != NULL && (tmp->data) <= (tmp->nextPtr->data)) {
        tmp = tmp->nextPtr;
        i++;
    }
    if (i == (argc - 2)) {
        printf("SORTED \n");
        return (1);
    }
    return (0);
}

t_node *ini_new_info_files(int num)
{
    t_node *file = malloc(sizeof(t_node));
    
    if (file == NULL)
        printf("Error\n");
    file->data = num;
    file->nextPtr = NULL;
    return file;
}

void create_new(t_node *file, int num)
{
    t_node *tmp = file;
    
    while (tmp->nextPtr != NULL) {
        tmp = tmp->nextPtr;
    }

    tmp->nextPtr = ini_new_info_files(num);
}

void save(int argc, char **argv, t_node *l_a)
{
    int i = 1;
    int num;
    while (i < argc) {
        num = my_getnbr(argv[i]);
        create_new(l_a, num);
        i++;
    }
}

void free_node(t_node *l_a, t_node *l_b)
{
    free(l_a);
    free(l_b);
}

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

void find_closer(t_variables *var, t_node **l_a, t_node **l_b)
{    
    if ((var->count_la / 2) < var->pos_smaller) { 
        var->pos_smaller = var->count_la - var->pos_smaller;
        var->side1 = 1;
    }

    if ((var->count_la / 2) < var->pos_bigger) { 
        var->pos_bigger = var->count_la - var->pos_bigger;
        var->side2 = 1;
    }

    if (var->pos_bigger >= var->pos_smaller)
        var->side = var->side2;
    else if (var->pos_bigger < var->pos_smaller)
        var->side = var->side1;

    if (var->side == 1) {
        while (var->pos_bigger > 0) {
            func_rra(*l_a);
            var->pos_bigger--;
        }
        func_pb(l_a, l_b, var);
    }
    else if (var->side == 0) {
        while (var->pos_smaller > 0) {
            func_ra(*l_a);
            var->pos_smaller--;
        }
        func_pb(l_a, l_b, var);
    }
    var->side = 0;
}

void algorithm_sort(t_node **l_a, t_node **l_b, t_variables *var)
{
    t_node *tmp_a = *l_a;
    var->smaller = (*l_a)->data;
    var->bigger = (*l_a)->data;
    var->pos_smaller = 0;
    var->pos_bigger = 0;
    int pos = 0;
    
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

    //printf("valor mes gran: %d\n", var->bigger);
    //printf("en la posicion: %d\n", var->pos_bigger);
    //printf("valor mes petit: %d\n", var->smaller);
    //printf("en la posicion: %d\n", var->pos_smaller);

    find_closer(var, l_a, l_b);
}


void algorithm_sort2(t_node **l_a, t_node **l_b, t_variables *var)
{
    t_node *tmp_a = *l_a;
    var->smaller = (*l_a)->data;
    var->bigger = (*l_a)->data;
    var->pos_smaller = 0;
    var->pos_bigger = 0;
    int pos = 0;
    
    while (var->count_lb != 0) {
        func_pa(l_a, l_b, var);
        if ((*l_a)->data > (*l_a)->nextPtr->data)
            func_ra(*l_a);
    }
}


int main(int argc, char **argv)
{
    t_node *l_a = malloc(sizeof(t_node *));
    t_node *l_b = malloc(sizeof(t_node *));
    t_variables var;
    var.count_la = (argc - 1);
    var.count_lb = 0;
    var.argc = argc;
    
    save(argc, argv, l_a);
    l_a = l_a->nextPtr; //NO Eliminar
    l_b = l_b->nextPtr; //NO Eliminar
    check_sorted(argc, l_a);
    while (check_sorted(argc, l_a) != 1 && var.count_la > 1) {
        printf("Sorted: %d\n", check_sorted(argc, l_a));
        algorithm_sort(&l_a, &l_b, &var);
    }
    algorithm_sort2(&l_a, &l_b, &var);
    printf("\n");
    printlinked(l_a);
    printlinked(l_b);
    free_node(l_a, l_b);
    return (0);
}