/*
** EPITECH PROJECT, 2021
** Sebas-i-victor-printf
** File description:
** myls.h
*/

#ifndef LIBRARIES_H_
#define LIBRARIES_H_

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void func_rra(t_node *l_a);
void func_rrr(t_node *l_a, t_node *l_b);
void func_ra(t_node *l_a);
void func_rr(t_node *l_a, t_node *l_b);
void func_pa(t_node **l_a, t_node **l_b, t_variables *var);
void func_pb(t_node **l_a, t_node **l_b, t_variables *var);
void func_sa(t_node *l_a, t_variables *var);
void func_sb(t_node *l_b, t_variables *var);
void func_sc(t_node *l_a, t_node *l_b, t_variables *var);
void printlinked(t_node *file);
int check_sorted(int argc, t_node *l_a);
t_node *ini_new_info_files(int num)


//void func_sa();
//void func_sb();
//void func_sc();
//void func_pa();
//void func_pb();
//void func_ra();
//void func_rb();
//void func_rr();
//void func_rra();
//void func_rrb();
//void func_rrr();
int my_getnbr(char const *str);



#endif