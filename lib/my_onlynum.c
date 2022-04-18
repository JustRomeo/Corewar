/*
** EPITECH PROJECT, 2019
** my only num
** File description:
** oui
*/

#include <stdlib.h>

char *my_onlynum(char *str)
{
    int y = 0;
    int p = 0;
    char *nstr = malloc(sizeof(char) * 12);

    while (str[y]) {
        if (str[y] < 58 && str[y] > 47) {
            nstr[p] = str[y];
            p ++;
        }
        y ++;
    }
    nstr[p] = '\0';
    return (nstr);
}
