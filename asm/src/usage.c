/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** usage of asm
*/

#include "asm.h"

int usage_asm(void)
{
    my_putstr("USAGE\n\t./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n\n\tfile_namefile in assembly language to be ");
    my_putstr("converted into file_name.cor, an\n\t\t");
    my_putstr("executable in the Virtual Machine\n");
    return (0);
}
