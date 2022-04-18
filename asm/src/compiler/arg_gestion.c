/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** arg_gestion
*/

#include "asm.h"

struct arg write_register(char *str)
{
    char str2[3];
    int i = 1;
    int j = 0;
    struct arg argument = {0, 1};

    while (str[i] != '\0') {
        str2[j] = str[i];
        j ++;
        i ++;
    }
    str2[j] = '\0';
    argument.arg = my_getnbr(str2);
    return (argument);
}

struct arg write_direct(char *str, int i, char **arr, char *name)
{
    int u = 1;
    int j = 0;
    char str2[4];
    struct arg argument = {0, 4};

    if (str[1] == ':')
        argument.arg = label_char_argument(arr, i, str);
    else {
        while (str[u] != '\0') {
            str2[j] = str[u];
            j ++;
            u ++;
        }
        str2[j] = '\0';
        argument.arg = my_getnbr(str2);
    }
    if (check_case_direct(name) == 2)
        argument.size = 2;
    return (argument);
}

struct arg write_indirect(char *str)
{
    struct arg argument = {0, 2};

    argument.arg = my_getnbr(str);
    return (argument);
}
