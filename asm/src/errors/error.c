/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** Global Error Gestion
*/

#include "asm.h"

int asm_global_e(char **str)
{
    if (str == NULL)
        return (84);
    if (error_name_comment(str, ".name", 128) == 0 ||
        error_name_comment(str, ".comment", 2048) == 0)
        return (84);
    if (func_e(str) == 84)
        return (84);
    return (0);
}
