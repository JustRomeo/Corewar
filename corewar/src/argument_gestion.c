/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** argument_gestion
*/

#include "asm.h"

void index_gestion(int fd, champion **champ, int j, int *pos)
{
    int r = 0;

    (*champ)->command[j]->argu[*pos] = malloc(sizeof(struct arg));
    read(fd, &r, 1);
    (*champ)->command[j]->argu[*pos]->arg = r;
    (*champ)->command[j]->argu[*pos]->size = 1;
    (*pos)++;
}

void direct_gestion(int fd, champion **champ, int j, int *pos)
{
    int r = 0;

    (*champ)->command[j]->argu[*pos] = malloc(sizeof(struct arg));
    if (check_case_direct((*champ)->command[j]->op.mnemonique) == 2) {
        read(fd, &r, 2);
        (*champ)->command[j]->argu[*pos]->arg = swap_short(r);
        (*champ)->command[j]->argu[*pos]->size = 2;
    }
    else {
        read(fd, &r, 4);
        (*champ)->command[j]->argu[*pos]->arg = int_little_to_big(r);
        (*champ)->command[j]->argu[*pos]->size = 4;
    }
    (*pos)++;
}

void indirect_gestion(int fd, champion **champ, int j, int *pos)
{
    int r = 0;

    (*champ)->command[j]->argu[*pos] = malloc(sizeof(struct arg));
    read(fd, &r, 2);
    (*champ)->command[j]->argu[*pos]->size = 2;
    (*champ)->command[j]->argu[*pos]->arg = swap_short(r);
    (*pos)++;
}