/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** decoupe_line
*/

#include "asm.h"

char **decoupe_line(char *str)
{
    char *str2 = beautifull_str(str);
    char **arr = my_str_to_word_array(str2, ',');

    return (arr);
}
