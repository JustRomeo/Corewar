/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** endian_gestion
*/

#include "asm.h"
#define IS_LITTLE_ENDIAN 0
#define IS_BIG_ENDIAN    1

short swap_short(short x)
{
    return (((x & 0x00ff) << 8) | ((x & 0xff00) >> 8));
}

int int_little_to_big(int x)
{
    return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00)
            | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}

int endian(void)
{
    int i = 1;
    char *p = (char *)&i;

    if (p[0] == 1)
        return (IS_LITTLE_ENDIAN);
    else
        return (IS_BIG_ENDIAN);
}
