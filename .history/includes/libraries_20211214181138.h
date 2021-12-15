/*
** EPITECH PROJECT, 2021
** Sebas-i-victor-printf
** File description:
** myls.h
*/

#ifndef LIBRARIES_H_
#define LIBRARIES_H_
#include "./structs.h"
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
int check_sorted(t_variables *var, t_node *l_a);
t_node *ini_new_info_files(int num);
void create_new(t_node *file, int num);
void save(int argc, char **argv, t_node *l_a);
void free_node(t_node *l_a, t_node *l_b);
int find_biggest_nbr(t_node *l_a);
int get_last_value(t_node *l_a);
void find_closer(t_variables *var, t_node **l_a, t_node **l_b);

int my_getnbr(char const *str);



#endif