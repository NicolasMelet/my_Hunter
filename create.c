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

int create_window(games *game)
{
    sfVideoMode mode = {1000, 700, 32};
    sfVector2f init_pos;

    init_pos.x = 200;
    init_pos.y = 200;
    game->bg_text = sfTexture_createFromFile("background.jpg", NULL);
    game->m_text = sfTexture_createFromFile("menu.png", NULL);
    game->window = sfRenderWindow_create(mode, "SFML window",
        sfResize | sfClose, NULL);
    if (!game->window || !game->bg_text || !game->m_text)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->bg_sprite = sfSprite_create();
    game->m_sprite = sfSprite_create();
    sfSprite_setTexture(game->bg_sprite, game->bg_text, sfTrue);
    sfSprite_setTexture(game->m_sprite, game->m_text, sfTrue);
    sfSprite_setPosition(game->m_sprite, init_pos);
    game->level = 0;
    game->score = 0;
    return 0;
}

sfVector2f get_init_pos_ran(void)
{
    sfVector2f init_pos;
    time_t t;

    srand(time(&t));
    init_pos.x = (rand() % 801) + 100;
    init_pos.y = 700;
    return init_pos;
}

int create_charac(chara *charac)
{
    sfVector2f init_pos = get_init_pos_ran();

    charac->ko = 0;
    set_rect(charac, 0, 110, 110);
    set_vectors(charac, init_pos);
    if (set_charac_sprite(charac, "ducks.png", init_pos) == 84)
        return 84;
    return 0;
}
