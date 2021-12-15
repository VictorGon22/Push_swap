/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Display string into console
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

void my_putstr(char const *str)
{
    int len;
    if (str) {
        len = my_strlen(str);
        if (len > 0)
            write(1, str, len);
    }
}
