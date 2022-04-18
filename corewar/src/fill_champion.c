/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** fill_champion
*/

#include "asm.h"

int fill_champ_stat(char *str, champion **champ)
{
    struct header_s head;
    int fd = open(str, O_RDONLY);

    (*champ) = malloc(sizeof(champion));
    if (champ == NULL)
        return (84);
    read(fd, &head, sizeof(struct header_s));
    (*champ)->name = my_strcpy((*champ)->name, head.prog_name);
    (*champ)->comment = my_strcpy((*champ)->comment, head.comment);
    (*champ)->size = int_little_to_big(head.prog_size);
    (*champ)->nb = -1;
    (*champ)->load_adress = -1;
    (*champ)->end_adress = -1;
    (*champ)->command = malloc(sizeof(struct command_s) * ((*champ)->size));
    if ((*champ)->command == NULL) {
        return (84);
    }
    fill_champ_command(fd, champ);
    return (0);
}

int find_champ(champion **champ, char **av, int ac, int i)
{
    if (my_strstr(av[i], ".cor") == 1) {
        if (fill_champ_stat(av[i], champ) == 84)
            return (84);
        if (fill_champ_arg(ac, av, champ, i) == 84)
            return (84);
        return (1);
    }
    return (0);
}

int fill_champ(champion **champ, int ac, char **av)
{
    int i = 0;
    int r = 0;
    int j = 0;

    while (av[i] != NULL) {
        r = find_champ(&champ[j], av, ac, i);
        if (r == 84)
            return (84);
        if (r == 1)
            j++;
        i++;
    }
    champ[j] = NULL;
    return (0);
}

int champ_arg(int ac, char **av, int i, champion **champ)
{
    if (my_strstr(av[i], "-n") == 1) {
        if (my_str_isnum(av[i + 1]) == 1)
            return (84);
        (*champ)->nb = my_getnbr(av[i + 1]);
        if ((*champ)->nb < 1 || (*champ)->nb > 4)
            return (84);
    }
    if (my_strstr(av[i], "-a") == 1) {
        if (my_str_isnum(av[i + 1]) == 1)
            return (84);
        (*champ)->load_adress = my_getnbr(av[i + 1]);
        (*champ)->end_adress = (*champ)->load_adress + (*champ)->size;
    }
    return (0);
}

int fill_champ_arg(int ac, char **av, champion **champ, int i)
{
    int j = i - 4;
    int r = 0;

    while (i >= j && i > 0) {
        r = champ_arg(ac, av, i, champ);
        if (r == 84)
            return (84);
        i--;
    }
    return (0);
}
