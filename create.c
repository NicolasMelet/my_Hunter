/*
** EPITECH PROJECT, 2022
** create
** File description:
** create
*/

#include <SFML/Graphics.h>
#include "header.h"
#include <stdlib.h>
#include <time.h>

int create_window(sfRenderWindow **window, sfVideoMode mode)
{
    *window = sfRenderWindow_create(mode, "SFML window",
        sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(*window, 60);
    return 0;
}

void set_vectors(chara *charac, sfVector2f init_pos)
{
    if (init_pos.x < 330)
        charac->dir_x = ((double) (rand() % 251));
    if (init_pos.x >= 330 && init_pos.x <= 660)
        charac->dir_x = ((double) (rand() % 501) - 250);
    if (init_pos.x > 660)
        charac->dir_x = ((double) (rand() % 251 - 250));
    charac->dir_y = -300;
}

void set_rect(chara *charac, int origin, int width, int height)
{
    charac->rect.top = 0;
    charac->rect.left = 0;
    charac->rect.width = 110;
    charac->rect.height = 110;
}

int set_sprite(chara *charac, char *image_path, sfVector2f init_pos)
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

int create_charac(chara *charac)
{
    sfVector2f init_pos;
    time_t t;

    srand(time(&t));
    init_pos.x = (rand() % 801) + 100;
    init_pos.y = 700;
    set_rect(charac, 0, 110, 110);
    set_vectors(charac, init_pos);
    if (set_sprite(charac, "ducks.png", init_pos) == 84)
        return 84;
    return 0;
}
