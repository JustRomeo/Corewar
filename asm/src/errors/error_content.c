/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** Error in functions content
*/

#include "asm.h"

int dir_check(char *str)
{
    if (str == NULL)
        return (ERROR);
    if (str[0] != '%')
        return (ERROR);
    return (SUCCESS);
}

int indir_check(char *str)
{
    if (str == NULL)
        return (ERROR);
    if (my_str_isnum(str) != 0)
        return (ERROR);
    return (SUCCESS);
}

int registre_check(char *str)
{
    if (str == NULL)
        return (ERROR);
    if (str[0] == 'r' && my_getnbr(my_onlynum(str)) < 17 &&
        my_getnbr(my_onlynum(str)) > 0)
        return (SUCCESS);
    return (ERROR);
}

static int function_content_end(char **tab)
{
    if ((my_strcmp(tab[0], "add") == 0 || my_strcmp(tab[0], "sub") == 0) &&
        (my_argvlen(tab) < 4 || registre_check(tab[1]) == ERROR ||
        registre_check(tab[2]) == ERROR || registre_check(tab[3]) == ERROR))
        return (ERROR);
    if ((my_strcmp(tab[0], "and") == 0 || my_strcmp(tab[0], "or") == 0 ||
        my_strcmp(tab[0], "xor") == 0) && (my_argvlen(tab) < 4 ||
                                            all_check(tab[1]) == ERROR ||
                                            all_check(tab[2]) == ERROR ||
                                            registre_check(tab[3]) == ERROR))
        return (ERROR);
    if ((my_strcmp(tab[0], "ldi") == 0 || my_strcmp(tab[0], "lldi") == 0) &&
        (my_argvlen(tab) < 4 || all_check(tab[1]) == ERROR ||
        dir_reg_check(tab[2]) == ERROR || registre_check(tab[3]) == ERROR))
        return (ERROR);
    if ((my_strcmp(tab[0], "ld") == 0 || my_strcmp(tab[0], "lld") == 0) &&
        (my_argvlen(tab) < 3 || dir_indir_check(tab[1]) == ERROR ||
        registre_check(tab[2]) == ERROR))
        return (ERROR);
    return (SUCCESS);
}

int function_content(char **tab)
{
    if (my_strcmp(tab[0], "aff") == 0 && (my_argvlen(tab) < 2 ||
                                            registre_check(tab[1]) == ERROR))
        return (ERROR);
    if (my_strcmp(tab[0], "st") == 0 && (my_argvlen(tab) < 3 ||
                                            registre_check(tab[1]) == ERROR ||
                                            indir_reg_check(tab[2]) == ERROR))
        return (ERROR);
    if (my_strcmp(tab[0], "sti") == 0 && (my_argvlen(tab) < 4 ||
                                        	registre_check(tab[1]) == ERROR ||
                                          	all_check(tab[2]) == ERROR ||
                                          	dir_reg_check(tab[3]) == ERROR))
        return (ERROR);
    if ((my_strcmp(tab[0], "zjmp") == 0 || my_strcmp(tab[0], "live") == 0 ||
        my_strcmp(tab[0], "fork") == 0 || my_strcmp(tab[0], "lfork") == 0)
        && (my_argvlen(tab) < 2 || dir_check(tab[1]) == ERROR))
        return (ERROR);
    return (function_content_end(tab));
}
