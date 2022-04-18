/*
** EPITECH PROJECT, 2018
** my_hexa.c
** File description:
** header
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *my_hexa(int nbr)
{
    int res = 0;
    int i = 0;
    char *resultat = malloc(sizeof(char) * 10);

    while (nbr > 0) {
        res = nbr % 16;
        nbr = nbr / 16;
        if (res < 10)
            resultat[i] = res + 48;
        if (res > 10)
            resultat[i] = res + 55;
        i ++;
    }
    return (my_revstr(resultat));
}
