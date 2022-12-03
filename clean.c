/*
** EPITECH PROJECT, 2022
** clean
** File description:
** clean
*/

#include <SFML/Graphics.h>
#include "header.h"

void clean_ress(chara *charac, games *game, globaltime *structime)
{
    sfClock_destroy(structime->clock);
    sfMusic_destroy(game->music);
    sfSprite_destroy(charac->sprite);
    sfSprite_destroy(game->bg_sprite);
    sfSprite_destroy(game->m_sprite);
    sfText_destroy(game->text);
    sfFont_destroy(game->font);
    sfTexture_destroy(charac->texture);
    sfTexture_destroy(game->bg_text);
    sfTexture_destroy(game->m_text);
    sfRenderWindow_destroy(game->window);
}
