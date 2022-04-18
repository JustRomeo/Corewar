/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** recherche une chaine dans une autre
*/

int my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0' && to_find[j] != '\0') {
        if (str[i + j] == to_find[j]) {
            j++;
        }
        else {
            j = 0;
            i++;
        }
    }
    if (str[i] == '\0')
        return (0);
    else if (to_find[j] == '\0')
        return (1);
}
