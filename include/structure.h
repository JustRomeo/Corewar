/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** structure
*/

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include "op.h"

typedef struct arg {
    int arg;
    int size;
} arg;

typedef struct pos {
    int pos;
    int i;
} pos;

typedef struct command_s {
    char *command;
    char **args;
    int **arg;
    struct arg **argu;
    int coding_byte;
    op_t op;
} command_t;

typedef struct champion
{
    char *name;
    char *comment;
    int nb;
    int size;
    int load_adress;
    int end_adress;
    struct command_s **command;
    int reg[REG_NUMBER];
} champion;

#endif
