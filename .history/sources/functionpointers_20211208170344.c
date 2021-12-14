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
    flags[0].op = "sa";
    flags[0].ptr = &func_l;
    flags[1].op = "sb";
    flags[1].ptr = &func_d;
    flags[2].op = "sc";
    flags[2].ptr = &func_w;
    flags[3].op = "pa";
    flags[3].ptr = &func_l;
    flags[4].op = "pb";
    flags[5].ptr = &func_d;
    flags[2].op = "ra";
    flags[2].ptr = &func_w;
    flags[0].op = "rb";
    flags[0].ptr = &func_l;
    flags[1].op = "rr";
    flags[1].ptr = &func_d;
    flags[2].op = "rra";
    flags[2].ptr = &func_w;
    flags[0].op = "rrb";
    flags[0].ptr = &func_l;
    flags[1].op = "rrr";
   
    

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