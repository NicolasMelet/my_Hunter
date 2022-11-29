/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include/header.h"
#include <stdlib.h>

int my_hunter(void);

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("Informations à venir\n");
        return 0;
    }
    return my_hunter();
}
