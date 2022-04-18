/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** compiler
*/

#include "asm.h"

static void write_name(header_t *head, int fd)
{
    write(fd, head, sizeof(header_t));
}

static int is_label_char(const char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i ++)
        if (c == LABEL_CHARS[i])
            return (1);
    return (0);
}

static int is_label(const char *line)
{
    int i = 0;

    while (is_label_char(line[i]))
        i ++;
    if (line[i] == LABEL_CHAR && line[i + 1] == '\0')
        return (1);
    return (0);
}

static int is_line_to_jump(char const *line)
{
    if (line[0] == '.')
        return (1);
    if (is_label(line))
        return (1);
    return (0);
}

int compile(char **lines, char *filename, header_t *head)
{
    int fd = create_file(filename);
    command_t *command = NULL;

    if (fd == -1)
        return (84);
    write_name(head, fd);
    for (int i = 0; lines[i] != NULL; i ++) {
        if (is_line_to_jump(lines[i]) == 0) {
            command = parse_line(lines[i]);
            write_command(command, fd);
            write_opcode(command, fd);
            check_commande(lines, i, fd);
        }
    }
    return (0);
}
