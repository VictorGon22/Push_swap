/*
** EPITECH PROJECT, 2021
** functio pointers
** File description:
** selection the operation
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void fill_flags(calculator *flags)
{
    flags[6].op = "rb";
    flags[6].ptr = &func_ra;
    flags[7].op = "rr";
    flags[7].ptr = &func_rr;
    flags[8].op = "rra";
    flags[8].ptr = &func_rra;
    flags[9].op = "rrb";
    flags[9].ptr = &func_rra;
    flags[10].op = "rrr";
    flags[10].ptr = &func_rrr;
}

void fill_flags(calculator *flags)
{
    flags[0].op = "sa";
    flags[0].ptr = &func_sa;
    flags[1].op = "sb";
    flags[1].ptr = &func_sb;
    flags[2].op = "sc";
    flags[2].ptr = &func_sc;
    flags[3].op = "pa";
    flags[3].ptr = &func_pa;
    flags[4].op = "pb";
    flags[4].ptr = &func_pb;
    flags[5].op = "ra";
    flags[5].ptr = &func_ra;
    fill_flags2(flags);
}

int func_pointer(char *filepath, char type)
{
    int i = 0;
    calculator flags[11];

    fill_flags(flags);
    while (i < 11) {
        if (type == flags[i].op)
            (*(flags[i].ptr))(filepath);
        i++;
    }
    return (0);
}