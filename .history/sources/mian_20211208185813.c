/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void create_new(t_node *file, char *filepath, char *name)
{
    t_node *tmp = file;

    while (tmp->nextPtr != NULL) {
        tmp = tmp->nextPtr;
    }
    tmp->nextPtr = ini_new_info_files(name, filepath);
}
void save(char **argv)
{
    int i = 1;
    int num;
    while (argv[i] != NULL) {
        l_a->num = my_getnbr(argv[i]);
        l_a.next
    }
}

int main(int argc, char **argv)
{
    t_node *l_a;
    t_node *l_b;

    save(argv, &l_a);
}
