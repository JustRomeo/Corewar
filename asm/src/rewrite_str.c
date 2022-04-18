/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** rewrite_str
*/

#include "yolotrom_asm.h"

char *rewrite_line(char *str)
{
    int i = 0;

    while (str[i] != '\n' && str[i] != '\0') {
        if (str[i] == '#') {
            str[i] = '\0';
            return (str);
        }
        i++;
    }
    str[i] = '\0';
    return (str);
}

char **rewrite_str(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        str[i] = rewrite_line(str[i]);
        i++;
    }
    return (str);
}