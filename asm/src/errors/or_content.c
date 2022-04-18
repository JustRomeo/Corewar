/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** Or check content
*/

#include "asm.h"

int dir_indir_check(char *str)
{
    if (str == NULL)
        return (ERROR);
    if (dir_check(str) == SUCCESS)
        return (SUCCESS);
    else if (dir_check(str) == ERROR)
        return (indir_check(str));
    else
        return (ERROR);
}

int dir_reg_check(char *str)
{
    if (str == NULL)
        return (ERROR);
    if (dir_check(str) == SUCCESS)
        return (SUCCESS);
    else if (dir_check(str) == ERROR)
        return (registre_check(str));
    else
        return (ERROR);
}

int indir_reg_check(char *str)
{
    if (str == NULL)
        return (ERROR);
    if (indir_check(str) == SUCCESS)
        return (SUCCESS);
    else if (indir_check(str) == ERROR)
        return (registre_check(str));
    else
        return (ERROR);
}

int all_check(char *str)
{
    if (str == NULL)
        return (ERROR);
    if (indir_check(str) == SUCCESS)
        return (SUCCESS);
    else if (indir_check(str) == ERROR) {
        if (dir_check(str) == SUCCESS)
            return (SUCCESS);
        else
            return (registre_check(str));
    }
    else
        return (ERROR);
}
