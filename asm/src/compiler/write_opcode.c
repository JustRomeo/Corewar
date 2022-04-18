/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** write_opcode
*/

#include <stdio.h>
#include "structure.h"
#include "my.h"
#include "asm.h"

static void fill_arg_type(char *arg, char *bin_opcode, int pos)
{
    switch (arg[0]) {
    case 'r': bin_opcode[pos + 1] = '1';
        break;
    case DIRECT_CHAR: bin_opcode[pos] = '1';
        break;
    case LABEL_CHAR: bin_opcode[pos] = '1';
        bin_opcode[pos + 1] = '1';
        break;
    default: break;
    }
    if (my_str_isnum(arg) == 0) {
        bin_opcode[pos] = '1';
        bin_opcode[pos + 1] = '1';
    }
}

static char *get_bin_opcode(char **args)
{
    char *bin_opcode = malloc(sizeof(char) * 9);
    int pos = 0;

    if (bin_opcode == NULL)
        return (NULL);
    for (int i = 0; i < 8; i ++)
        bin_opcode[i] = '0';
    bin_opcode[8] = '\0';
    for (int i = 0; args[i] != NULL && i < 4; i ++) {
        fill_arg_type(args[i], bin_opcode, pos);
        pos += 2;
    }
    return (bin_opcode);
}

static int is_special_function(char *name)
{
    const char *functions[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; functions[i] != NULL; i ++)
        if (my_strcmp(functions[i], name) == 0)
            return (1);
    return (0);
}

int write_opcode(command_t *command, int fd)
{
    int opcode = 0;

    if (is_special_function(command->command))
        return (1);
    opcode = bin_to_dec(get_bin_opcode(command->args));
    if (opcode == -1)
        return (84);
    write(fd, &opcode, 1);
    return (1);
}
