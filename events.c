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
    if (game->event.mouseButton.x > 403 && game->event.mouseButton.x < 572 &&
        game->event.mouseButton.y > 404 && game->event.mouseButton.y < 482) {
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
        set_score(game);
        repos_charac(charac, game);
        charac->bounce = 0;
        game->ko += 1;
    }
}

void pause_game(games *game)
{
    if (game->pause == 1 && game->event.key.code == sfKeyP)
        game->pause = 0;
    else if (game->event.key.code == sfKeyP)
        game->pause = 1;
}

void analyse_events(games *game, chara *charac)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtMouseButtonPressed && game->level != 0 &&
        game->pause == 0)
        duck_detection(game, charac);
    if (game->event.type == sfEvtMouseButtonPressed && game->level == 0)
        click_play(game);
    if (game->event.type == sfEvtKeyPressed && game->level != 0)
        pause_game(game);
}
