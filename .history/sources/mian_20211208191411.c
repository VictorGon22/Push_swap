/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

int chek_sorted(t_node *l_a)
{
    t_node *tmp;
    tmp = l_a->nextPtr;

    while (tmp->nextPtr != NULL && (tmp->data) > (l_a->data))
        tmp = tmp->nextPtr;
        l_a = l_a->nextPtr;
    }
}

void save(char **argv, t_node *l_a)
{
    int i = 1;
    int num;
    
    while (argv[i] != NULL) {
        l_a->data = my_getnbr(argv[i]);
        l_a->nextPtr = l_a;
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
