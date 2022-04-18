/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** Transfor a binary in hexa str
*/

#include <stddef.h>
#include <stdio.h>

char *my_bintohex(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_putint_in_str(char *str, int z);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
static int bintodec(char *bin)
{
    int res = 0;
    int m2 = 2;
    int y = 1;

    bin = my_revstr(bin);
    if (bin[0] == '1')
        res ++;
    while (bin[y]) {
        if (bin[y] == '1')
            res += m2;
        m2 = m2 * 2;
        y ++;
    }
    return (res);
}

char *my_bintohex(char *str)
{
    char *dec = my_strcpy(dec, my_hexa(bintodec(str)));

    return (NULL);
}
