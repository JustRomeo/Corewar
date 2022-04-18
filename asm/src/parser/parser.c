/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parser
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "structure.h"
#include "asm.h"

command_t *parse_line(char *line)
{
    command_t *command = malloc(sizeof(command_t));
    char **args = decoupe_line(line);

    if (args == NULL || command == NULL)
        return (NULL);
    if (args[0][my_strlen(args[0]) - 1] == ':') {
        command->command = args[1];
        command->args = &args[2];
    }
    else {
        command->command = args[0];
        command->args = &args[1];
    }
    return (command);
}
