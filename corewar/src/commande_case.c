/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** commande_case
*/

#include "asm.h"

int check_case_direct(char *name)
{
    if (my_str(name, "zjmp") == 0 || 
        (my_str(name, "ldi") == 0 && my_strlen(name) == 3) ||
        my_str(name, "sti") == 0 || my_str(name, "fork") == 0 
        || my_str(name, "lfork") == 0)
        return (2);
    return (4);
}

int add_code_bytes(char *name)
{
    if (my_str(name, "zjmp") == 0 || 
        (my_str(name, "ldi") == 0 && my_strlen(name) == 3) ||
        my_str(name, "live") == 0 || my_str(name, "fork") == 0 
        || my_str(name, "lfork") == 0)
        return (1);
    return (2);
}