/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *copy_filename(char *filename)
{
    char *str = malloc(sizeof(char) * (my_strlen(filename) + 5));
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (filename[i] != '.' && filename[i] != '\0') {
        str[i] = filename[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int create_file(char *filename)
{
    char *str = NULL;
    int fd = 0;

    str = copy_filename(filename);
    my_strcat(str, ".cor");
    fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    free(str);
    return (fd);
}
