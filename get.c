/*
** EPITECH PROJECT, 2022
** get
** File description:
** get
*/

#include <SFML/Graphics.h>
#include "header.h"
#include <stdlib.h>
#include <time.h>

sfVector2f get_init_pos_ran(void)
{
    sfVector2f init_pos;
    time_t t;

    srand(time(&t));
    init_pos.x = (rand() % 801) + 100;
    init_pos.y = 700;
    return init_pos;
}

void get_time(globaltime *structime)
{
    structime->time = sfClock_getElapsedTime(structime->clock);
    structime->seconds += structime->time.microseconds / 1000000.0;
    sfClock_restart(structime->clock);
}
