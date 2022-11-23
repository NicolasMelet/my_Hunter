/*
** EPITECH PROJECT, 2022
** header
** File description:
** header
*/

#ifndef HEADER_H
    #define HEADER_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct character {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} chara;

typedef struct timeClock {
    sfClock *clock;
    sfTime time;
    float seconds;
} time;

void my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
void manage_mouse_click(sfMouseButtonEvent event);
void analyse_events(sfRenderWindow *window, sfEvent event);
int create_window(sfRenderWindow **window, sfVideoMode mode);
int create_charac(chara *charac);
void clean_ress(chara *charac, sfRenderWindow *window);
void move_rect(sfIntRect *rect, int offset, int max_value);
void animate(time *structime, chara *charac);

#endif
