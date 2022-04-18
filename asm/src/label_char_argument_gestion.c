/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** label_char_argument_gestion
*/

#include "asm.h"

char *write_label(char *str)
{
    int i = 0;
    int j = 0;
    char *label = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] == '%' || str[i] == ':')
        i ++;
    while (str[i] != '\0') {
        label[j] = str[i];
        i ++;
        j ++;
    }
    label[j] = '\0';
    label = my_strcat(label, ":");
    return (label);
}

int check_before_after(char **str, char *arg)
{
    int i = 0;

    while (str[i] != NULL) {
        if (my_strstr(str[i], arg) == 1)
            return (i);
        i ++;
    }
    return (i);
}

int count_byte(char **str, int pos, int i)
{
    int count = 0;
    char **arr = NULL;

    while (pos < i) {
        arr = decoupe_line(str[pos]);
        count = count + check_if_command(arr);
        free_tab(arr);
        pos ++;
    }
    return (count);
}

int neg_byte(char **str, int pos, int i)
{
    int count = 0;
    char **arr = NULL;

    pos --;
    while (pos >= i) {
        arr = decoupe_line(str[pos]);
        count = count + check_if_command(arr);
        pos --;
        free_tab(arr);
    }
    return (count);
}


int label_char_argument(char **str, int pos, char *arg)
{
    char *label = write_label(arg);
    int i = check_before_after(str, label);
    int count = 0;

    if (i > pos)
        count = count_byte(str, pos, i);
    if (i < pos)
        count = -1 * neg_byte(str, pos, i);
    free(label);
    return (count);
}
