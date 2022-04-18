/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** error
*/

#include "asm.h"

int recup_dump_n(int ac, char **av)
{
    if (my_strstr(av[1], "-dump") == 1 && ac > 2)
        return (my_getnbr(av[2]));
    return (-1);
}

int check_champion(char *str)
{
    int fd = 0;

    if (my_strstr(str, ".cor") == 1) {
        fd = open(str, O_RDONLY);
        if (fd < 0) {
            return (-1);
        }
        close(fd);
        return (1);
    }
    return (0);
}

int find_nb_champion(char **av)
{
    int nb = 0;
    int r = 0;
    int i = 1;

    while (av[i] != NULL) {
        r = check_champion(av[i]);
        if (r == 1)
            nb++;
        if (r == -1)
            return (-1);
        i ++;
    }
    return (nb);
}

int check_load_error(int load, int end, champion **champ)
{
    int i = 0;

    while (champ[i] != NULL) {
        if (load > champ[i]->load_adress && load < champ[i]->end_adress)
            return (84);
        if (end > champ[i]->load_adress && end < champ[i]->end_adress)
            return (84);
        i++;
    }
    return (0);
}

int error_placing(champion **champ)
{
    int j = 0;
    int load = 0;
    int end = 0;

    while (champ[j] != NULL) {
        load = champ[j]->load_adress;
        end = champ[j]->end_adress;
        if (check_load_error(load, end, champ) == 84)
            return (84);
        j++;
    }
    return (0);
}