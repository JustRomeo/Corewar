/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#include <stdlib.h>
#include "corewar.h"
#include "structure.h"

int corewar(champion **champions)
{
    unsigned char *memory = init_memory();

    if (memory == NULL)
        return (84);
    free(memory);
    return (0);
}
