/*
** EPITECH PROJECT, 2022
** test init
** File description:
** test init
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include "header.h"

void get_time(globaltime *structime)
{
    structime->time = sfClock_getElapsedTime(structime->clock);
    structime->seconds += structime->time.microseconds / 1000000.0;
    sfClock_restart(structime->clock);
}

void reset(games *game)
{
    game->level = 0;
    game->score = 0;
    set_score(game);
    game->ko = 0;
}

int menu(games *game, chara *charac, globaltime *structime)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        analyse_events(game, charac);
    }
    if (game->level != 0) {
        if (create_charac(charac) == 84)
            return 84;
        structime->clock = sfClock_create();
    }
    m_window_display(game);
    return 0;
}

int main_loop(games *game,
            chara *charac, globaltime *structime)
{
    if (game->level == 0)
        return menu(game, charac, structime);
    get_time(structime);
    animate(structime, charac);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        analyse_events(game, charac);
    }
    lv_window_display(game, charac);
    if (game->ko == 8)
        reset(game);
    return 0;
}

int my_hunter(void)
{
    games game;
    chara charac;
    globaltime structime;

    if (create_window(&game) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game.window)) {
        if (main_loop(&game, &charac, &structime) == 84)
            return 84;
    }
    clean_ress(&charac, &game);
    return 0;
}
