/*
** EPITECH PROJECT, 2022
** display
** File description:
** display
*/
#include "header.h"

void window_display(sfRenderWindow *window, chara *charac)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, charac->sprite, NULL);
    sfRenderWindow_display(window);
}
