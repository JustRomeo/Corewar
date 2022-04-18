/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "asm.h"

static char **fill_doss(char *filename)
{
    FILE *fd = fopen(filename, "r");
    char **str = malloc(sizeof(char *) * 2);
    size_t n = 0;
    int i = 0;

    if (fd == NULL || str == NULL)
        return (NULL);
    str[0] = NULL;
    str[1] = NULL;
    while (getline(&str[i], &n, fd) != -1) {
        if (str[i][0] != '\n' && str[i][0] != '#') {
            str = reallocation(str, i + 1);
            i ++;
        }
    }
    str[i] = NULL;
    fclose(fd);
    return (str);
}

static void file_head(char **str, struct header_s *head)
{
    head->magic = COREWAR_EXEC_MAGIC;
    head->magic = int_little_to_big(head->magic);
    for (int i = 0; i != PROG_NAME_LENGTH; i++)
        head->prog_name[i] = '\0';
    for (int i = 0; i != COMMENT_LENGTH; i++)
        head->comment[i] = '\0';
    get_name(str, head);
    get_comment(str, head);
    head->prog_size = get_prog_size(str);
    head->prog_size = int_little_to_big(head->prog_size);
}

int main(int ac, char **av)
{
    char **str = NULL;
    struct header_s head;

    if (ac != 2)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (usage_asm());
    str = fill_doss(av[1]);
    if (asm_global_e(str))
        return (84);
    str = rewrite_str(str);
    file_head(str, &head);
    if (compile(str, av[1], &head) == 84)
        return (84);
    free_tab(str);
    return (0);
}
