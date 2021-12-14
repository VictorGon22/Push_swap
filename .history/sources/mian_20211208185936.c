/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void save(char **argv, t_node *l_a)
{
    int i = 1;
    int num;
    while (argv[i] != NULL) {
        l_a->data = my_getnbr(argv[i]);
        l_a->nextPtr = l_a;
    }
    l_a
}

int main(int argc, char **argv)
{
    t_node *l_a;
    t_node *l_b;

    save(argv, &l_a);
}
