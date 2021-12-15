/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Get the length of a string
*/

int my_strlen(char const *str)
{
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return (length);
}
