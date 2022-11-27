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
        rect->left -= 330;
}

void redirect_duck(chara *charac)
{
    sfVector2f position = sfSprite_getPosition(charac->sprite);

    if (position.x < 0 && charac->vect.x < 0) {
        charac->dir_x *= -1;
        charac->heading = 0;
        move_rect(&charac->rect, 0, 330);
    }
    if (position.x > 1000 - 110 && charac->vect.x > 0) {
        charac->dir_x *= -1;
        charac->heading = 1;
        move_rect(&charac->rect, 330, 660);
    }
    if (position.y < 0 && charac->vect.y < 0)
        charac->dir_y *= -1;
    if (position.y > 700 - 110 && charac->vect.y > 0)
        charac->dir_y *= -1;
}

void animate(globaltime *structime, chara *charac)
{
    charac->vect.x = charac->dir_x * structime->time.microseconds / 1000000.0;
    charac->vect.y = charac->dir_y * structime->time.microseconds / 1000000.0;
    redirect_duck(charac);
    sfSprite_move(charac->sprite, charac->vect);
    if (structime->seconds > 0.2) {
        move_rect(&charac->rect, 110, 330 + (330 * charac->heading));
        structime->seconds = 0;
    }
    sfSprite_setTextureRect(charac->sprite, charac->rect);
}
