/*
** EPITECH PROJECT, 2022
** clean
** File description:
** clean
*/

#include <SFML/Graphics.h>

void clean_ress(chara *charac, sfRenderWindow *window)
{
    sfSprite_destroy(charac->sprite);
    sfTexture_destroy(charac->texture);
    sfRenderWindow_destroy(window);
}
