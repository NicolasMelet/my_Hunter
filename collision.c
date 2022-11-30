/*
** EPITECH PROJECT, 2022
** collision
** File description:
** collision
*/

#include "header.h"

void bouncing_x(chara *charac)
{
    charac->dir_x *= -1;
    charac->bounce += 1;
}

void bouncing_y(chara *charac)
{
    charac->dir_y *= -1;
    charac->bounce += 1;
}

void redirect_duck(chara *charac)
{
    sfVector2f position = sfSprite_getPosition(charac->sprite);

    if (position.x < 0 && charac->vect.x < 0) {
        bouncing_x(charac);
        charac->heading = 0;
        move_rect(&charac->rect, 0, 330);
    }
    if (position.x > 1000 - 110 && charac->vect.x > 0) {
        bouncing_x(charac);
        charac->heading = 1;
        move_rect(&charac->rect, 330, 660);
    }
    if (position.y < 0 && charac->vect.y < 0) {
        bouncing_y(charac);
    }
    if (position.y > 700 - 110 && charac->vect.y > 0) {
        bouncing_y(charac);
    }
}
