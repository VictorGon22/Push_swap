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
    t_node *final;
    
    data = tmp->data;
    while (tmp->nextPtr != NULL) {
        tmp = tmp->nextPtr;
        next = tmp->data;
        tmp->data = data;
        data = next;
    }
    tmp = l_a;
    tmp->data = data;
}

void func_rrr(t_node *l_a, t_node *l_b)
{
    func_rra(l_a);
    func_rra(l_b);
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
}

void func_rr(t_node *l_a, t_node *l_b)
{
    func_ra(l_a);
    func_ra(l_b);
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
}

void func_sc(t_node *l_a, t_node *l_b, t_variables *var)
{
    func_sa(l_a, var);
    func_sb(l_b, var);
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
    t_node *tmp = l_a->nextPtr;
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
void algorithm_sort(t_node *l_a, t_node *l_b, t_variables *var)
{
    t_node *tmp_a = l_a;
    int i = 0;
    int counteriguals = 0;
    int mid_value = find_biggest_nbr(l_a) / 2;
    int last_value = get_last_value(l_a);

    if (check_sorted(var->argc, l_a) == 1)
        printf("ORDENAT");
    else {
        printf("biggestnbr%d\n", mid_value);
        while (i != 1) {
            if (tmp_a->data < mid_value)
                func_pb(&l_a, &l_b, var);
            else
                i = 1;
            tmp_a = tmp_a->nextPtr;
        }
        printf("numeros a la llista a: %d\n", var->count_la);
        printf("numeros a la llista b: %d\n", var->count_lb);
        i = 0;
        while (i < var->count_la)
        {
            printf("Cuants entra   ");
            i++;
            printf("Valor de tmp: %d\n", tmp_a->data);
            if (tmp_a->data < mid_value)
                func_pb(&l_a, &l_b, var);
            else
            func_ra(l_a);
        } 
        printlinked(l_a);
        printlinked(l_b);
    }
}

int main(int argc, char **argv)
{
    t_node *l_a = malloc(sizeof(t_node *));
    t_node *l_b = malloc(sizeof(t_node *));
    t_variables var;
    var.count_la = argc - 1;
    var.count_lb = 0;
    var.argc = argc;
    
    save(argc, argv, l_a);
    l_a = l_a->nextPtr; //NO Eliminar
    l_b = l_b->nextPtr; //NO Eliminar
    algorithm_sort(l_a, l_b, &var);
    //check_sorted(argc, l_a);
    /*
    func_sa(l_a, &var);
    printf("\nl_a ");
    printlinked(l_a);
    printf("\nl_b ");
    printlinked(l_b);

    func_pb(&l_a, &l_b, &var);
    func_pb(&l_a, &l_b, &var);
    func_pb(&l_a, &l_b, &var);
    printf("\nl_a ");
    printlinked(l_a);
    printf("\nl_b ");
    printlinked(l_b);

    func_ra(l_a);
    func_ra(l_b);
    printf("\nl_a ");
    printlinked(l_a);
    printf("\nl_b ");
    printlinked(l_b);

    func_rrr(l_a, l_b);
    printf("\nl_a ");
    printlinked(l_a);
    printf("\nl_b ");
    printlinked(l_b);

    func_sa(l_a, &var);
    printf("\nl_a ");
    printlinked(l_a);
    printf("\nl_b ");
    printlinked(l_b);

    func_pa(&l_a, &l_b, &var);
    func_pa(&l_a, &l_b, &var);
    func_pa(&l_a, &l_b, &var);
    printf("\nl_a ");
    printlinked(l_a);
    printf("\nl_b ");
    printlinked(l_b);
    */

    //printlinked(l_b);
    
    //func_pb(l_a, l_b, &var);
    //printlinked(l_a);
    //printf("l_b datakjkj: %d\n", l_b->nextPtr->data);
    //printlinked(l_b);
    //func_sa(l_a, &var);
    //printlinked(l_a);
    free_node(l_a, l_b);
    return (0);
}