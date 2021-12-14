/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

int chek_sorted(int argc, t_node *l_a)
{
    t_node *tmp;
    tmp = l_a->nextPtr;
    int i = 0;
    while (tmp->nextPtr != NULL && (tmp->data) > (tmp->nextPtr->data)) {
        tmp = tmp->nextPtr;
        i++;
    }
    if (i == (argc - 2))
        return (1);
    return (0);
}
void create_new(t_node *file)
{
   t_node *tmp = file;

    while (tmp->nextPtr != NULL) {
        tmp = tmp->nextPtr;
    }
    tmp->data = ;
}

void save(char **argv, t_node *l_a)
{
    int i = 1;
    int num;
    while (argv[i] != NULL) {
        num = my_getnbr(argv[i]);
        create_new(&l_a, num);
    }
    l_a->nextPtr = NULL;
}

int main(int argc, char **argv)
{
    t_node *l_a;
    t_node *l_b;

    save(argv, &l_a);
    chack_sorted(&l_a);
}
