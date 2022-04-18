/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** fill_champion_struct
*/

#include "asm.h"

void fill_champ_code(champion **champ, char code, int j)
{
    int i = 0;

    while (op_tab[i].code != code) {
        i++;
    }
    (*champ)->command[j]->op = op_tab[i];
}

void fill_commande_argument2(int fd, champion **champ, int j, char *bin)
{
    int i = 0;
    int pos = 0;

    while (bin[i] != '\0') {
        if (bin[i] == '0' && bin[i + 1] == '1') {
            index_gestion(fd, champ, j, &pos);
        }
        if (bin[i] == '1' && bin[i + 1] == '0') {
            direct_gestion(fd, champ, j, &pos);
        }
        if (bin[i] == '1' && bin[i + 1] == '1') {
            indirect_gestion(fd, champ, j, &pos);
        }
        i+=2;
    }
    (*champ)->command[j]->argu[pos] = NULL;
}

void fill_command_argument(int fd, champion **champ, int j)
{
    int coding_byte = 0;
    char *bin = NULL;

    bin = fill_bin(fd, coding_byte, champ, j);
    (*champ)->command[j]->argu = malloc(sizeof(int) * ((*champ)->size));
    fill_commande_argument2(fd, champ, j, bin);
}

int fill_champ_command(int fd, champion **champ)
{
    char code;
    int j = 0;

    while (read(fd, &code, 1) != 0) {
        (*champ)->command[j] = malloc(sizeof(struct command_s));
        fill_champ_code(champ, code, j);
        fill_command_argument(fd, champ, j);
        code = 0;
        j++;
    }
    (*champ)->command[j] = NULL;
    return (0);
}