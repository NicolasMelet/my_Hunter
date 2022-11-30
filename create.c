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

int set_bg(games *game)
{
    game->bg_text = sfTexture_createFromFile("background.jpg", NULL);
    if (!game->bg_text)
        return 84;
    game->bg_sprite = sfSprite_create();
    sfSprite_setTexture(game->bg_sprite, game->bg_text, sfTrue);
    return 0;
}

int set_m(games *game)
{
    sfVector2f init_pos;

    init_pos.x = 200;
    init_pos.y = 200;

    game->m_text = sfTexture_createFromFile("menu.png", NULL);
    if (!game->m_text)
        return 84;
    game->m_sprite = sfSprite_create();
    sfSprite_setTexture(game->m_sprite, game->m_text, sfTrue);
    sfSprite_setPosition(game->m_sprite, init_pos);
    return 0;
}

int set_score_text(games *game)
{
    sfVector2f init_pos;

    init_pos.x = 750;
    init_pos.y = 50;
    game->text_score = sfText_create();
    game->font = sfFont_createFromFile("Pointless.ttf");
    set_score(game);
    sfText_setFont(game->text_score, game->font);
    sfText_setCharacterSize(game->text_score, 20);
    sfText_setPosition(game->text_score, init_pos);
    return 0;
}

int create_window(games *game)
{
    sfVideoMode mode = {1000, 700, 32};

    game->window = sfRenderWindow_create(mode, "SFML window",
        sfResize | sfClose, NULL);
    if (!game->window || set_bg(game) == 84 || set_m(game) == 84)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->str_score = "SCORE : 0";
    game->level = 0;
    game->score = 0;
    game->ko = 0;
    game->pause = 0;
    set_score_text(game);
    return 0;
}

int create_charac(chara *charac)
{
    sfVector2f init_pos = get_init_pos_ran();

    set_rect(charac, 0, 110, 110);
    set_vectors(charac, init_pos);
    charac->bounce = 0;
    if (set_charac_sprite(charac, "ducks.png", init_pos) == 84)
        return 84;
    return 0;
}
