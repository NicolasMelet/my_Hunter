/*
** EPITECH PROJECT, 2022
** display
** File description:
** display
*/
#include "header.h"

void lv_window_display(games *game, chara *charac)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->bg_sprite, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfRenderWindow_drawSprite(game->window, charac->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void m_window_display(games *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->bg_sprite, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfRenderWindow_drawSprite(game->window, game->m_sprite, NULL);
    sfRenderWindow_display(game->window);
}
