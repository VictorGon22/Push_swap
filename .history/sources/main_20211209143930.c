/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"



void func_ra(t_node **begin)
{
    t_node *current;
    t_node *next;
    t_node *previous;

    previous = NULL;
    current = *begin;
    next = (*begin)->nextPtr;
    while (current != NULL) {
        current->nextPtr = previous;
        previous = current;
        current = next;
        if (next != NULL)
            next = next->nextPtr;
    }
    *begin = previous;
}


void func_pb(t_node *l_a, t_node *l_b, t_variables *var)
{
    t_node *tmp_b = malloc(sizeof(t_node*)); // guardem el primer punter
    t_node *tmp_a = l_a->nextPtr;
    tmp_b->data = tmp_a->data;
    var->count_lb ++;
    printf("valor de l_b: %d\n", tmp_b->data);
    tmp_b->nextPtr = NULL;
    *l_b = *tmp_b;
    *l_a = *tmp_a;
     
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
        //tmp = tmp->nextPtr;
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
    //tmp = tmp->nextPtr;
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
void createLinkedList(int numberOfNodes)
{
    t_ *newNode;
    node *currentNodes;
    int nodeData;
    int nodeCtr;

    firstNode = (node *) malloc(sizeof(node));
    if (firstNode == NULL) {
        printf("memory cant be allocated");
    } else {
        printf("input num:  ");
        scanf("%d", &nodeData);

        firstNode->filesize = nodeData;
        firstNode->next = NULL;
        currentNodes = firstNode;
        
        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++) {
            newNode = (node *)malloc(sizeof(node));
            if (newNode == NULL) {
                printf("Memory can not be allocated");
                exit (84);
            } else {
                scanf("%d", &nodeData);
                newNode->filesize = nodeData;
                newNode->next = NULL;
                currentNodes->next = newNode;
                currentNodes = currentNodes->next;
            } 
        }
    }
}


void save(int argc, char **argv, t_node *l_a)
{
    int i = 1;
    int num;
    while (i < argc) {
        printf("valor entrada: %s\n", argv[i]);
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
    
    save(argc, argv, l_a);
    check_sorted(argc, l_a);
    //func_sa(l_a, &var);
    //func_sb(l_b, &var);
    //func_sc(l_a, l_b, &var);
    func_ra(&l_a);
    //func_sa(l_a, &var);
    printlinked(l_a);
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