/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct func_poiner
{
    char op;
    void (*ptr)(char *filepath);
} calculator;

struct node
{
    int data;
    struct node *nextPtr;
} node;
#endif

