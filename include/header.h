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
    double seconds;
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
    int bounce;
} chara;

typedef struct gamestruct {
    sfRenderWindow *window;
    sfTexture *bg_text;
    sfSprite *bg_sprite;
    sfTexture *m_text;
    sfSprite *m_sprite;
    sfText *text;
    sfFont *font;
    sfEvent event;
    sfMusic *music;
    int is_over;
    int level;
    int pause;
    int score;
    int best_score;
    char *str_score;
    int ko;
} games;

void my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
void lv_window_display(games *game, chara *charac);
void m_window_display(games *game);
void manage_mouse_click(sfMouseButtonEvent event, chara *charac);
void analyse_events(games *game, chara *charac);
int create_window(games *game);
void set_rect(chara *charac, int origin, int width, int height);
int set_charac_sprite(chara *charac, char *image_path, sfVector2f init_pos);
void set_vectors(chara *charac, sfVector2f init_pos, games *game);
int create_charac(chara *charac, games *game);
void clean_ress(chara *charac, games *game, globaltime *structime);
void move_rect(sfIntRect *rect, int offset, int max_value);
void animate(globaltime *structime, chara *charac, games *game);
int my_strcmp(char const *s1 ,char const *s2);
int my_strlen(char const *str);
void repos_charac(chara *charac, games *game);
sfVector2f get_init_pos_ran(void);
void set_score(games *game);
char *int_to_str(int score);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
sfVector2f get_init_pos_ran(void);
void get_time(globaltime *structime);
void redirect_duck(chara *charac);
void infos(void);
void set_best_score(games *game);

#endif
