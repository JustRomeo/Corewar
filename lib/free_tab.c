/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** free_tab
*/

#include <stddef.h>
#include <stdlib.h>

void free_tab(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}