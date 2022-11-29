/*
** EPITECH PROJECT, 2022
** clean
** File description:
** clean
*/

#include <SFML/Graphics.h>
#include "include/header.h"

void clean_ress(chara *charac, games *game)
{
    sfSprite_destroy(charac->sprite);
    sfSprite_destroy(game->bg_sprite);
    sfText_destroy(game->text_score);
    sfFont_destroy(game->font);
    sfTexture_destroy(charac->texture);
    sfTexture_destroy(game->bg_text);
    sfRenderWindow_destroy(game->window);
}
