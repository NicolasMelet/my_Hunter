/*
** EPITECH PROJECT, 2022
** sprite mod
** File description:
** sprite mod
*/

#include <SFML/Graphics.h>
#include "header.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

void animate(time *structime, chara *charac)
{
    if (structime->seconds > 33) {
        move_rect(&charac->rect, 110, 330);
        structime->seconds = 0;
        sfClock_restart(structime->clock);
    }
}
