/*
** EPITECH PROJECT, 2019
** CPE_bootstrap_corewar_2018
** File description:
** asm.h
*/

#ifndef ASM_H_
#define ASM_H_

#include <stdio.h>
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
#include "macros.h"

#define IS_LITTLE_ENDIAN 0
#define IS_BIG_ENDIAN 1

static const unsigned char command_bytes[16] = {
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x10
};

static const op_t op_tab[] =
{
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index"}, {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index"}, {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"}, {0, 0, {0}, 0, 0, 0}
};

int func_e(char **av);
int asm_global_e(char **str);
int tab_length(char **arr);
char **get_all_file(FILE *fd);
int write_on_file(char **str, int fd, char code);
int error_name_comment(char **str, char *to_find, int l_w);
void get_comment(char **str, struct header_s *head);
void get_name(char **str, struct header_s *head);
void *my_memset(void *data, int c, size_t n);
char *copy_filename(char *filename);
int compile(char **lines, char *filename, header_t *head);
int create_file(char *filename);
int get_prog_size(char **str);
char **decoupe_line(char *str);
command_t *parse_line(char *line);
int write_opcode(command_t *command, int fd);
int bin_to_dec(char *bin);
int label_char_argument(char **str, int pos, char *arg);
char **rewrite_str(char **str);
void write_command(command_t *command, int fd);
int check_if_command(char **arr);
int add_code_bytes(char *name);
int check_case_direct(char *name);
struct arg write_register(char *str);
struct arg write_direct(char *str, int i, char **arr, char *name);
struct arg write_indirect(char *str);
int check_commande(char **str, int u, int fd);
int little_to_big(int x);
int endian(void);
short swap_short(short x);
int int_little_to_big(int x);
int usage_asm(void);

/*-----CHECK_ERRORS-----*/
int function_content(char **tab);
int dir_check(char *str);
int indir_check(char *str);
int registre_check(char *str);
int dir_indir_check(char *str);
int dir_reg_check(char *str);
int indir_reg_check(char *str);
int all_check(char *str);
void indirect_gestion(int fd, champion **champ, int j, int *pos);
void direct_gestion(int fd, champion **champ, int j, int *pos);
void index_gestion(int fd, champion **champ, int j, int *pos);

//corewar
int find_nb_champion(char **av);
int recup_dump_n(int ac, char **av);
int fill_champ(champion **champ, int ac, char **av);
int fill_champ_stat(char *str, champion **champ);
int fill_champ_arg(int ac, char **av, champion **champ, int i);
int find_champion_size(int fd);
int fill_champ_command(int fd, champion **champ);
char *fill_special_case(char *name);
char *fill_bin(int fd, int coding_byte, champion **champ, int j);
char *fill_bin_with_zero(char *bin);
int fill_nb(champion **champ, int i);
int fill_adress_champ(champion **champ, int nb_champion);
int fill_nb_champ(champion **champ, int nb_champion);
int no_champ_is_placed(champion **champ, int i, int nb_champion);
int one_champ_is_placed(champion **champ, int i, int nb_champion);
void find_best_place(champion **champ, int i, int nb_champion);
int error_placing(champion **champ);
#endif /* !YOLOTROM_ASM_H_ */
