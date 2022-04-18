/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_memory
*/

#include <stdlib.h>
#include "op.h"

void mem_set_memory(unsigned char *memory)
{
    for (int i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
}

unsigned char *init_memory(void)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * MEM_SIZE);

    if (memory == NULL)
        return (NULL);
    mem_set_memory(memory);
    return (memory);
}
