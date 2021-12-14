/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"

void fill_flags(calculator *flags)
{
    flags[0].op = 'l';
    flags[0].ptr = &func_l;
    flags[1].op = 'd';
    flags[1].ptr = &func_d;
    flags[2].op = 'w';
    flags[2].ptr = &func_w;

}

int func_pointer(char *filepath, char type)
{
    int i = 0;
    calculator flags[3];

    fill_flags(flags);
    while (i < 3) {
        if (type == flags[i].op)
            (*(flags[i].ptr))(filepath);
        i++;
    }
    return (0);
}