/*
** EPITECH PROJECT, 2022
** set_score
** File description:
** set_score
*/

#include "header.h"
#include <stdlib.h>

void set_score(games *game)
{
    char str[10];
    char *score = int_to_str(game->score);
    char *cpy = score;
    sfVector2f init_pos;

    init_pos.x = 748;
    init_pos.y = 50;
    my_strcpy(str, "Score : ");
    game->str_score = my_strcat(str, score);
    free(score);
    sfText_setString(game->text, str);
    sfText_setPosition(game->text, init_pos);
}

void set_best_score(games *game)
{
    char str[15];
    char *score = int_to_str(game->best_score);
    char *cpy = score;
    sfVector2f init_pos;

    init_pos.x = 650;
    init_pos.y = 50;
    my_strcpy(str, "Best score : ");
    game->str_score = my_strcat(str, score);
    free(score);
    sfText_setString(game->text, str);
    sfText_setPosition(game->text, init_pos);
}
