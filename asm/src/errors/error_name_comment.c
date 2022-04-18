/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_name_comment
*/

#include "asm.h"

int lenght_word(char *str, int lenght)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '"' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return (0);
    i++;
    while (str[i] != '"' && str[i] != '\0') {
        i++;
        nb++;
    }
    if (nb > lenght || str[i] == '\0')
        return (0);
    return (1);
}

int error_name_comment(char **str, char *to_find, int l_w)
{
    int j = 0;

    while (str[j] != NULL) {
        if (my_strstr(str[j], to_find) == 1 && lenght_word(str[j], l_w) != 0) {
            return (1);
        }
        j++;
    }
    return (0);
}
