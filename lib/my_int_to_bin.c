/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** my_int_to_bin
*/

#include <stddef.h>
#include <stdlib.h>
char *my_revstr(char *str);

int taille_num(int nb)
{
    int t = 0;

    while (nb / 10) {
        t++;
        nb = nb / 10;
    }
    return (t);
}

char *my_int_to_bin(unsigned int nb)
{
    int n = 1;
    int j = 0;
    int result = 0;
    char *src = malloc(sizeof(char) * taille_num(nb));

    while (nb > 0) {
        n = nb % 2;
        src[j] = n + '0';
        nb = nb / 2;
        j++;
    }
    return (my_revstr(src));
}
