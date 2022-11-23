/*
** EPITECH PROJECT, 2022
** events
** File description:
** events
*/

#include <SFML/Graphics.h>
#include "header.h"

void manage_mouse_click(sfMouseButtonEvent event)
{
    my_putstr("Mouse x=");
    my_putnbr(event.x);
    my_putstr(" y=");
    my_putnbr(event.y);
    my_putchar('\n');
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton);
}
