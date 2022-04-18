/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** write_command
*/

#include "asm.h"
#include "structure.h"
#include "my.h"

void write_command(command_t *command, int fd)
{
    int i = 0;

    while (i < 16) {
        if (my_strcmp(command->command, op_tab[i].mnemonique) == 0) {
            write(fd, &command_bytes[i], sizeof(unsigned char));
            return;
        }
        i ++;
    }
}
