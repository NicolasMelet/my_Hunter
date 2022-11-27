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

typedef struct timeClock {
    sfClock *clock;
    sfTime time;
    float seconds;
    int curr_frame;
} globaltime;

typedef struct character {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f vect;
    float dir_x;
    float dir_y;
    int heading;
} chara;

void my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
void window_display(sfRenderWindow *window, chara *charac);
void manage_mouse_click(sfMouseButtonEvent event, chara *charac);
void analyse_events(sfRenderWindow *window, sfEvent event, chara *charac);
int create_window(sfRenderWindow **window, sfVideoMode mode);
int create_charac(chara *charac);
void clean_ress(chara *charac, sfRenderWindow *window);
void move_rect(sfIntRect *rect, int offset, int max_value);
void animate(globaltime *structime, chara *charac);
int my_strcmp(char const *s1 ,char const *s2);
int my_strlen(char const *str);

#endif
