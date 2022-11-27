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

int main_loop(sfRenderWindow *window,
            chara *charac, globaltime *structime, sfEvent *event)
{
    structime->time = sfClock_getElapsedTime(structime->clock);
    structime->seconds += structime->time.microseconds / 1000000.0;
    sfClock_restart(structime->clock);
    animate(structime, charac);
    sfSprite_setTextureRect(charac->sprite, charac->rect);
    while (sfRenderWindow_pollEvent(window, event)) {
        analyse_events(window, *event, charac);
    }
    window_display(window, charac);
    return 0;
}

int my_hunter(void)
{
    sfVideoMode mode = {1000, 700, 32};
    sfRenderWindow *window;
    chara charac;
    globaltime structime;
    sfEvent event;

    structime.clock = sfClock_create();
    if (create_window(&window, mode) == 84 || create_charac(&charac) == 84)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        main_loop(window, &charac, &structime, &event);
    }
    clean_ress(&charac, window);
    return 0;
}
