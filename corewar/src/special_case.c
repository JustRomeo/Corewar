/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** special_case
*/

#include "asm.h"

char *fill_special_case(char *name)
{
    char *bin = NULL;

    if (my_str(name, "zjmp") == 0)
        bin = my_strcpy(bin, "10");
    if (my_str(name, "ldi"))
        bin = my_strcpy(bin, "101001");
    if (my_str(name, "live"))
        bin = my_strcpy(bin, "10");
    if (my_str(name, "fork"))
        bin = my_strcpy(bin, "10");
    if (my_str(name, "lfork"))
        bin = my_strcpy(bin, "10");
    return (bin);
}