/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** fill_adress
*/

#include "asm.h"

int load_adress(int diff[], int add[], int i, int nb_champion)
{
    int j = 0;
    int nb = 0;
    int pos = 0;

    while (diff[j] != 0) {
        if (diff[j] > nb) {
            nb = diff[j];
            pos = j;
        }
        j++;
    }
    nb = nb / nb_champion;
    nb = nb + add[i];
    return (nb);
}

void find_best_place(champion **champ, int i, int nb_champion)
{
    int add[] = {0};
    int diff[] = {0};
    int j = 0;
    int u = 0;

    while (champ[j] != NULL) {
        if (champ[j]->load_adress != -1) {
            add[u] = champ[j]->end_adress;
            u++;
        }
        j++;
    }
    for (int r = 0; r < u; r++) {
        diff[r] = add[r] - add[r + 1];
        if (diff[r] < 0)
            diff[r] = diff[r] * -1;
        r++;
        diff[r] = 0;
    }
    champ[i]->load_adress = load_adress(diff, add, i, nb_champion);
    champ[i]->end_adress = champ[i]->load_adress + champ[i]->size;
}

int one_champ_is_placed(champion **champ, int i, int nb_champion)
{
    int j = 0;
    int add_pos = 0;
    int pos = 0;
    int nb = 0;

    while (champ[j] != NULL) {
        if (champ[j]->load_adress != -1) {
            add_pos = champ[j]->end_adress;
            nb++;
        }
        j++;
    }
    if (nb > 1)
        return (0);
    pos = (MEM_SIZE % nb_champion) + add_pos;
    champ[i]->load_adress = pos;
    champ[i]->end_adress = pos + champ[i]->size;
    return (1);
}

int no_champ_is_placed(champion **champ, int i, int nb_champion)
{
    int j = 0;

    while (champ[j] != NULL) {
        if (champ[j]->load_adress != -1)
            return (0);
        j++;
    }
    champ[i]->load_adress = 0;
    champ[i]->end_adress = champ[i]->load_adress + champ[i]->size;
    return (1);
}