/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** bin_to_dec
*/

#include "stdlib.h"
#include "my.h"

static int calc_pow(int nbr, int pow)
{
    int result = nbr;

    if (pow == 0)
        return (1);
    if (pow == 1)
        return (nbr);
    for (int i = 1; i < pow; i ++)
        result = result * nbr;
    return (result);
}

int bin_to_dec(char *bin)
{
    int i = 0;
    int dec = 0;

    if (bin == NULL)
        return (-1);
    my_revstr(bin);
    while (bin[i] != '\0') {
        if (bin[i] == '1')
            dec += calc_pow(2, i);
        i ++;
    }
    return (dec);
}
