/*
** EPITECH PROJECT, 2018
** StrCPY
** File description:
** Fonction StrCpy
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (i = 0; src[i] != '\0'; i ++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
