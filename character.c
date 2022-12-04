/*
** EPITECH PROJECT, 2022
** character
** File description:
** character
*/

#include <SFML/Graphics.h>
#include "header.h"
#include <stdlib.h>
#include <time.h>

void set_vectors(chara *charac, sfVector2f init_pos, games *game)
{
    if (init_pos.x < 330)
        charac->dir_x = ((double) (rand() % 251)) *
            ((double) 1 + ((double) game->score / 500 / 10));
    if (init_pos.x >= 330 && init_pos.x <= 660)
        charac->dir_x = ((double) (rand() % 501) - 250) *
            ((double) 1 + ((double) game->score / 500 / 10));
    if (init_pos.x > 660)
        charac->dir_x = ((double) (rand() % 251 - 250)) *
            ((double) 1 + ((double) game->score / 500 / 10));
    charac->dir_y = -300 * ((double) 1 + ((double) game->score / 500 / 10));
}

void set_rect(chara *charac, int origin, int width, int height)
{
    charac->rect.top = 0;
    charac->rect.left = 0;
    charac->rect.width = 110;
    charac->rect.height = 110;
}

int set_charac_sprite(chara *charac, char *image_path, sfVector2f init_pos)
{
    charac->texture = sfTexture_createFromFile(image_path, NULL);
    if (!charac->texture)
        return 84;
    charac->sprite = sfSprite_create();
    sfSprite_setTexture(charac->sprite, charac->texture, sfTrue);
    sfSprite_setPosition(charac->sprite, init_pos);
    if (charac->dir_x >= 0)
        charac->heading = 0;
    else {
        charac->heading = 1;
        move_rect(&charac->rect, 330, 660);
    }
    return 0;
}

void repos_charac(chara *charac, games *game)
{
    sfVector2f init_pos = get_init_pos_ran();

    set_vectors(charac, init_pos, game);
    sfSprite_setPosition(charac->sprite, init_pos);
    if (charac->dir_x >= 0 && charac->heading == 1) {
        move_rect(&charac->rect, 0, 330);
        charac->heading = 0;
    }
    if (charac->dir_x < 0 && charac->heading == 0) {
        charac->heading = 1;
        move_rect(&charac->rect, 330, 660);
    }
}
