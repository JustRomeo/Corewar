/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Fonction
*/

#include <stddef.h>

int my_str_isnum(char const *str)
{
    int y = 0;

    if (str == NULL)
        return (1);
    while (str[y]) {
        if (str[y] < 48 || str[y] > 58)
            return (1);
        y ++;
    }
    return (0);
}
