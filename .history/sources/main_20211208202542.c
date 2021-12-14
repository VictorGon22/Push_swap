/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void printlinked(t_node *file)
{
    t_node *tmp = file;

    while (tmp != NULL) {
        printf("Entra");
        printf("%d ",tmp->data);
        tmp = tmp->nextPtr;
    }
    printf("\n");
}

int check_sorted(int argc, t_node *l_a)
{
    t_node *tmp = malloc(sizeof(t_node *));
    tmp = l_a;
    int i = 0;
    while (tmp->nextPtr != NULL && (tmp->data) > (tmp->nextPtr->data)) {
        tmp = tmp->nextPtr;
        i++;
    }
    if (i == (argc - 2)) {
        return (1);
        free(tmp);
    }
    return (0);
}
t_node *ini_new_info_files(int num)
{
    t_node *file = malloc(sizeof(t_node));
    
    if (file == NULL)
        printf("error\n");
    file->data = num;
    f
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
    l_a->nextPtr = NULL;
}

int main(int argc, char **argv)
{
    t_node *l_a = malloc(sizeof(t_node *));
    t_node *l_b = malloc(sizeof(t_node *));

    save(argv, l_a);
    check_sorted(argc, l_a);
    printlinked(l_a);
    free(l_a);
    free(l_b);
    return (0);
}
