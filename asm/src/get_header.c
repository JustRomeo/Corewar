/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_header
*/

#include "asm.h"

void get_comment(char **str, struct header_s *head)
{
    int j = 0;
    int i = 0;
    int u = 0;

    while (my_strstr(str[j], ".comment") == 0)
        j++;
    while (str[j][i] != '"')
        i++;
    i++;
    while (str[j][i] != '"') {
        head->comment[u] = str[j][i];
        i++;
        u++;
    }
    head->comment[u] = '\0';
}

void get_name(char **str, struct header_s *head)
{
    int j = 0;
    int i = 0;
    int u = 0;

    while (my_strstr(str[j], ".name") == 0)
        j++;
    while (str[j][i] != '"')
        i++;
    i++;
    while (str[j][i] != '"') {
        head->prog_name[u] = str[j][i];
        i++;
        u++;
    }
    head->prog_name[u] = '\0';
}
