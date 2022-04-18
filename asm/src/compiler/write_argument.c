/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** write_argument
*/

#include "asm.h"

void write_function(int fd, struct arg *argument)
{
    if (endian() == 0) {
        if (argument->size == 4)
            argument->arg = int_little_to_big(argument->arg);
        if (argument->size == 2)
            argument->arg  = swap_short(argument->arg);
    }
    write(fd, &(argument->arg), argument->size);
    argument->arg = 0;
    argument->size = 4;
}

int write_argument(int i, char **str, int pos, int fd)
{
    int u = i + 1;
    struct arg argument = {0, 4};
    char **arr = decoupe_line(str[pos]);

    while (arr[u] != NULL) {
        if (arr[u][0] == 'r') {
            argument = write_register(arr[u]);
            write_function(fd, &argument);
        }
        else if (arr[u][0] == '%') {
            argument = write_direct(arr[u], pos, str, arr[i]);
            write_function(fd, &argument);
        }
        else {
            argument = write_indirect(arr[u]);
            write_function(fd, &argument);
        }
        u ++;
    }
    return (1);
}

static int check_name_commande(char **arr, char **str, pos pos_arg, int fd)
{
    int j = 0;
    int i = pos_arg.i;

    while (op_tab[j].mnemonique != NULL) {
        if (my_str(arr[i], op_tab[j].mnemonique) == 0 
            && arr[i][my_strlen(arr[i]) - 2] != ':')
            return (write_argument(i, str, pos_arg.pos, fd));
        j ++;
    }
    return (0);
}

int check_commande(char **str, int u, int fd)
{
    pos pos_arg = {u, 0};
    char **arr = decoupe_line(str[u]);

    while (arr[pos_arg.i] != NULL) {
        if (check_name_commande(arr, str, pos_arg, fd) == 1)
            return (1);
        pos_arg.i ++;
    }
    return (0);
}
