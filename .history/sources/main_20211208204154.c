/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void()
    func_sa (l_a);
void func_sa (t_node *l_a)
{
    int valuetmp;

    t_node *tmp = l_a;
    tmp = tmp->nextPtr;
    valuetmp = tmp->data;
    tmp->data = tmp->nextPtr->data;
    tmp->nextPtr->data = valuetmp;
}

void func_sb (t_node *l_b)
{
    int valuetmp;

    t_node *tmp = l_b;
    tmp = tmp->nextPtr;
    valuetmp = tmp->data;
    tmp->data = tmp->nextPtr->data;
    tmp->nextPtr->data = valuetmp;
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
    t_node *tmp = malloc(sizeof(t_node *));
    tmp = l_a;
    tmp = tmp->nextPtr;
    int i = 0;
    while (tmp->nextPtr != NULL && (tmp->data) <= (tmp->nextPtr->data)) {
        tmp = tmp->nextPtr;
        i++;
    }
    if (i == (argc - 2)) {
        printf("SORTED \n");
        return (1);
        free(tmp);
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

    if (argc < 3) {
        free_node(l_a, l_b);
        return (84);
    }
    save(argv, l_a);
    check_sorted(argc, l_a);
    func_sa(l_a);
    printlinked(l_a);
    free_node(l_a, l_b);
    return (0);
}
