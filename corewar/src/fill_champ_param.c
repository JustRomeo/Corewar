/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** fill_champ_param
*/

#include "asm.h"

int fill_nb(champion **champ, int i)
{
    int list[4] = {1, 2, 3, 4};
    int j = 0;
    int u = 0;

    while (champ[j] != NULL) {
        if (champ[j]->nb == 1)
            list[0] = 0;
        if (champ[j]->nb == 2)
            list[1] = 0;
        if (champ[j]->nb == 3)
            list[2] = 0;
        if (champ[j]->nb == 3)
            list[3] = 0;
        j++;
    }
    while (u != 4) {
        if (list[u] != 0)
            return (list[u]);
        u++;
    }
    return (0);
}

int fill_nb_champ(champion **champ, int nb_champion)
{
    int i = 0;

    while (champ[i] != NULL) {
        if (champ[i]->nb == -1)
            champ[i]->nb = fill_nb(champ, i);
        i++;
    }
    return (0);
}

int fill_adress(champion **champ, int i, int nb_champion)
{
    if (no_champ_is_placed(champ, i, nb_champion) == 1) 
        return (0);
    if (one_champ_is_placed(champ, i, nb_champion) == 1) 
        return (0);
    else  
        find_best_place(champ, i, nb_champion);
    return (0);
}

int fill_adress_champ(champion **champ, int nb_champion)
{
    int i = 0;

    while (champ[i] != NULL) {
        if (champ[i]->load_adress == -1) {
            fill_adress(champ, i, nb_champion);
        }
        i++;
    }
    if (error_placing(champ) == 84)
        return (84);
    return (0);
}