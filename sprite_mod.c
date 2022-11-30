/*
** EPITECH PROJECT, 2022
** sprite mod
** File description:
** sprite mod
*/

#include <SFML/Graphics.h>
#include "header.h"

void is_over(games *game, chara *charac)
{
    sfVector2f position = sfSprite_getPosition(charac->sprite);

    if (position.x < -110 || position.x > 1110 ||
        position.y < -110 || position.y > 810)
        game->is_over = 1;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left -= 330;
}

void animate(globaltime *structime, chara *charac, games *game)
{
    charac->vect.x = charac->dir_x * structime->time.microseconds / 1000000.0;
    charac->vect.y = charac->dir_y * structime->time.microseconds / 1000000.0;
    if (charac->bounce < 3 || charac->vect.y > 0)
        redirect_duck(charac);
    sfSprite_move(charac->sprite, charac->vect);
    is_over(game, charac);
    if (structime->seconds > 0.2) {
        move_rect(&charac->rect, 110, 330 + (330 * charac->heading));
        structime->seconds = 0;
    }
    sfSprite_setTextureRect(charac->sprite, charac->rect);
}
