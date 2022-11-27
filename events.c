/*
** EPITECH PROJECT, 2022
** events
** File description:
** events
*/

#include <SFML/Graphics.h>
#include "header.h"

void manage_mouse_click(sfMouseButtonEvent event, chara *charac)
{
    sfVector2f position = sfSprite_getPosition(charac->sprite);

    if (event.x > position.x && event.x < position.x + 110 &&
        event.y > position.y && event.y < position.y + 110)
        my_putstr("We got him\n");
}

void analyse_events(sfRenderWindow *window, sfEvent event, chara *charac)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, charac);
}
