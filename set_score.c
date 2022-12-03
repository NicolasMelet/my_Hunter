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

    my_strcpy(str, "Score : ");
    game->str_score = my_strcat(str, score);
    free(score);
    sfText_setString(game->text, str);
}
