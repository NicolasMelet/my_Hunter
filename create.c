/*
** EPITECH PROJECT, 2022
** create
** File description:
** create
*/

#include <SFML/Graphics.h>
#include "header.h"

int create_window(sfRenderWindow **window, sfVideoMode mode)
{
    *window = sfRenderWindow_create(mode, "SFML window",
        sfResize | sfClose, NULL);
    if (!window)
        return 84;
    return 0;
}

int create_charac(chara *charac)
{
    charac->rect.top = 0;
    charac->rect.left = 0;
    charac->rect.width = 110;
    charac->rect.height = 110;
    charac->texture = sfTexture_createFromFile("ducks.jpg", NULL);
    if (!charac->texture)
        return 84;
    charac->sprite = sfSprite_create();
    sfSprite_setTexture(charac->sprite, charac->texture, sfTrue);
    return 0;
}

void clean_ress(chara *charac, sfRenderWindow *window)
{
    sfSprite_destroy(charac->sprite);
    sfTexture_destroy(charac->texture);
    sfRenderWindow_destroy(window);
}
