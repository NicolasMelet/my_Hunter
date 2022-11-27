/*
** EPITECH PROJECT, 2022
** events
** File description:
** events
*/

#include <SFML/Graphics.h>
#include "header.h"

void click_play(games *game)
{
    if (game->event.mouseButton.x > 390 && game->event.mouseButton.x < 560 &&
        game->event.mouseButton.y > 400 && game->event.mouseButton.y < 480) {
        game->level = 1;
    }
}

void duck_detection(games *game, chara *charac)
{
    sfVector2f position = sfSprite_getPosition(charac->sprite);

    if (game->event.mouseButton.x > position.x &&
        game->event.mouseButton.x < position.x + 110 &&
        game->event.mouseButton.y > position.y &&
        game->event.mouseButton.y < position.y + 110) {
        game->score += 500;
        my_putnbr(game->score);
        my_putchar('\n');
        repos_charac(charac);
        charac->ko += 1;
    }
}

void analyse_events(games *game, chara *charac)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtMouseButtonPressed && game->level != 0)
        duck_detection(game, charac);
    if (game->event.type == sfEvtMouseButtonPressed && game->level == 0)
        click_play(game);
}
