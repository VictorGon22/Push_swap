/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct s_variables
{
    int count_la;
    int count_lb;
    int argc;
    char **argv;
    int mid_value;
    int smaller;
    int bigger;
    int pos_smaller;
    int pos_bigger;
    int side1;
    int side2;
    int side;
    int pos_to_move = 0;
    int tmp_small;
    int tmp_big;

} t_variables;

typedef struct func_poiner
{
    char op;
    void (*ptr)(char *filepath);
} calculator;

typedef struct s_node
{
    int data;
    struct s_node *nextPtr;
} t_node;


#endif

