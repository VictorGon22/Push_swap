/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void create_new(t_info_files *file, char *filepath, char *name)
{
    t_info_files *tmp = file;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ini_new_info_files(name, filepath);
}
void save(char **argv)
{
    int i = 1;
    int num;
    while (argv[i] != NULL) {
        num = my_getnbr(argv[i]);
        l_a =             
    }
}

int main(int argc, char **argv)
{
    t_node *l_a;
    t_node *l_b;

    save(argv, &l_a);
}
