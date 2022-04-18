/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** Error Functions
*/

#include "asm.h"

static int func_two(char **tab)
{
    if (my_strcmp(beautifull_str(tab[0]), "ldi") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "sti") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "fork") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "lld") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "lldi") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "lfork") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "aff") == 0)
        return (FIND);
    return (NOTFIND);
}

static int func_one(char **tab)
{
    if (my_strcmp(beautifull_str(tab[0]), "live") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "ld") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "st") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "add") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "sub") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "and") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "or") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "xor") == 0)
        return (FIND);
    if (my_strcmp(beautifull_str(tab[0]), "zjmp") == 0)
        return (FIND);
    return (func_two(tab));
}

static int check_command(char **tab)
{
    if (tab[0][my_strlen(tab[0]) - 1] != ':' && tab[0][0] != '.') {
        if (func_one(tab) != FIND)
            return (ERROR);
        if (function_content(tab) != SUCCESS)
            return (ERROR);
    }
    return (FIND);
}

int func_e(char **av)
{
    int y = 0;
    char **tab = NULL;

    while (av[y] != NULL) {
        tab = my_str_to_word_array(av[y], ',');
        if (check_command(tab) == ERROR)
            return (ERROR);
        y ++;
    }
    return (SUCCESS);
}
