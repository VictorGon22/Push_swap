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
#include "./structs.h"

char *change_date(char *str);
char *date(char *name, char *fullpath);
int total(char *name, char *fullpath);
int link_counts(char *name, char *fullpath);
char *user_name(char *name, char *fullpath);
char *goup_name(char *name, char *fullpath);
int size(char *name, char *fullpath);
char *permisions(char *name, char *fullpath);
void printlinked_d(t_info_files *file);
void printlinked(t_info_files *file);
void errormanager_general(t_var *var);
void errormanager_directories(char *dir);
char *my_strcat(char *dest, char const *src);
int func_pointer(char *filepath, char type);
void func_l(char *filepath);
void func_ld(char *filepath);
void func_d(char *filepath);
void func_w(char *filepath);
t_info_files *ini_new_info_files(char* name, char* filepath);
void create_new(t_info_files *file, char *filepath, char *name);
char *func_fullpath(char *filepath, char *name, char *fullpath);
t_info_files *sortSize(int numberOfNodes, t_info_files *firstNode, int reverse);

t_info_files *sort_file_size_reversed(t_info_files *list, int len, int i);
t_info_files *sort_file_size(t_info_files *list, int reverse);
void sort_file_name_reversed(t_info_files *list, int i, int len);
void sort_file_name_notreversed(t_info_files *list, int i, int len);
void sort_file_name(t_info_files *list, int reverse, int len);
//void save_info (t_info_files *file, t_info_1_file *tmp);
t_info_files *sort_file_size_notreversed(t_info_files *list, int len, int i);

#endif