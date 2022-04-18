/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** get_prog_size
*/

#include "asm.h"

int get_argument_size(char **arr, int i)
{
    int size = 0;
    int u = i + 1;

    while (arr[u] != NULL) {
        if (arr[u][0] == 'r')
            size++;
        else if (arr[u][0] == '%')
            size = size + check_case_direct(arr[i]);
        else
            size += 2;
        u ++;
    }
    size += add_code_bytes(arr[i]);
    return (size);
}

static int intermediate_function(char **arr, int i)
{
    int j = 0;

    while (op_tab[j].mnemonique != NULL) {
        if (my_str(arr[i], op_tab[j].mnemonique) == 0 
            && arr[i][my_strlen(arr[i]) - 2] != ':')
            return (get_argument_size(arr, i));
        j ++;
    }
    return (0);
}

int check_if_command(char **arr)
{
    int i = 0;
    int size = 0;

    while (arr[i] != NULL) {
        size = intermediate_function(arr, i);
        if (size != 0)
            return (size);
        i ++;
    }
    return (0);
}

int get_prog_size(char **str)
{
    int i = 2;
    char **arr = NULL;
    int size = 0;

    while (str[i] != NULL) {
        arr = decoupe_line(str[i]);
        size = size + check_if_command(arr);
        free_tab(arr);
        i ++;
    }
    return (size);
}
