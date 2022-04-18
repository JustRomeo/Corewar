/*
** EPITECH PROJECT, 2019
** clone_corewar
** File description:
** main
*/

#include "asm.h"

static int usage(void)
{
    my_putstr("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_putstr("[-a load_address] prog_name] ...\n\nDESCRIPTION\n\t-dump ");
    my_putstr("nbr_cycle dumps the memory after the nbr_cycle execution ");
    my_putstr("(if the round isn’t\n\t\t\talready over) with the following ");
    my_putstr("format: 32 bytes/line in\n\t\t\thexadecimal (A0BCDEFE1DD3...)");
    my_putstr("\n\n\t-n prog_number sets the next program’s number. By ");
    my_putstr("default, the first free number\n\t\t\tin the parameter order");
    my_putstr("\n\n\t-a load_address sets the next program’s loading address");
    my_putstr(". When no address is\n\t\t\tspecified, optimize the addresses ");
    my_putstr("so that the processes are as far\n\t\t\taway from each other ");
    my_putstr("as possible. The addresses are MEM_SIZE modulo");
    return (0);
}

int main(int ac, char **av)
{
    int dump = -1;
    champion **champ = NULL;
    int nb_champion = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (usage());
    dump = recup_dump_n(ac, av);
    nb_champion = find_nb_champion(av);
    if (nb_champion < 2 || nb_champion > 4)
        return (84);
    champ = malloc(sizeof(champion) * (nb_champion + 1));
    if (champ == NULL)
        return (84);
    if (fill_champ(champ, ac, av) == 84)
        return (84);
    if (fill_nb_champ(champ, nb_champion) == 84 
        || fill_adress_champ(champ, nb_champion) == 84)
        return (84);
    return (0);
}
