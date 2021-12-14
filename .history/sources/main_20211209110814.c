/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void func_pb(t_node *l_a, t_node *l_b, t_variables *var)
{
    t_node *tmp_b = l_b; // guardem el primer punter
    tmp_b = l_a;
    tmp_b->nextPtr = l_b;
    l_a = l_a->nextPtr;
}

void func_pb2(t_node *l_a, t_node *l_b, t_variables *var) // VICTOR
{
    t_node *tmp_b = l_b; // guardem el primer punter
    *l_b = *l_a;
    printf("valor de l_b: %d", );
    //tmp_b->nextPtr = l_b;
    // guardar primer valor de l_a a l_b ,
    // copiar tots els valors restants radera
    // eliminar primer valor de l_a i asignar el segon com a primer
    //l_a = l_a->nextPtr;
}
void func_sa(t_node *l_a, t_variables *var)
{
    int valuetmp;
    t_node *tmp = l_a;
    tmp = tmp->nextPtr;
    if (var->count_la >= 2) { // funciona
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
    tmp = tmp->nextPtr;
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
    tmp = tmp->nextPtr;
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

void save(char **argv, t_node *l_a)
{
    int i = 1;
    int num;
    while (argv[i] != NULL) {
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

int main(int argc, char **argv)
{
    t_node *l_a = malloc(sizeof(t_node *));
    t_node *l_b = malloc(sizeof(t_node *));
    t_variables var;
    var.count_la = argc - 1;
    var.count_lb = 0;
    //if (argc < 3) {
    //    free_node(l_a, l_b);
    //    return (84);
    //}
    save(argv, l_a);
    check_sorted(argc, l_a);
    //func_sa(l_a, &var);
    //func_sb(l_b, &var);
    //func_sc(l_a, l_b, &var);
    printlinked(l_a);
    printlinked(l_b);
    //func_pb(l_a, l_b, &var);
    func_pb2(l_a, l_b, &var); // Victor Prova
    printlinked(l_a);
    printlinked(l_b);
    free_node(l_a, l_b);
    return (0);
}