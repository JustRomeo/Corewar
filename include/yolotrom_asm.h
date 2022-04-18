/*
** EPITECH PROJECT, 2019
** CPE_bootstrap_corewar_2018
** File description:
** asm
*/

#ifndef ASM_H
#define ASM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "my.h"
#include "structure.h"
#include "op.h"

int asm_global_e(char **str);
int tab_length(char **arr);
char **get_all_file(FILE *fd);
int write_on_file(char **str, int fd, char code);
int error_name_comment(char **str, char *to_find, int l_w);
void get_comment(char **str, struct header_s *head);
void get_name(char **str, struct header_s *head);
void *my_memset(void *data, int c, size_t n);
char *copy_filename(char *filename);
char **rewrite_str(char **str);
#endif /* !YOLOTROM_ASM_H_ */
