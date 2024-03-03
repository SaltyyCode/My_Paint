/*
** EPITECH PROJECT, 2024
** paint.h
** File description:
** .h file for my_paint
*/

#ifndef PAINT
    #define PAINT

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdbool.h>

typedef enum {
    BRUSH,
    ERASER
} Tool;

typedef struct window {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfTexture *bgtexture;
    sfSprite *bgsprite;
    sfRenderTexture *drawzone;
    bool isDrawing;
    Tool current;
} Window;

typedef struct brush {
    sfColor color;
    float radius;
} Brush;

typedef enum {
    BTN_IDLE,
    BTN_HOVER,
    BTN_PRESSED
} ButtonState;

typedef struct {
    sfRectangleShape* shape;
    ButtonState state;
} Button;

typedef struct colors {
    sfSprite *color;
    sfTexture *color_texture;
    sfIntRect colorect;
    float x;
    float y;
} color_s;


extern Button bouton;
extern Button bouton2;

//my_event.c
int analyse_event(Window *app);
void handlemouse(Window *app);
void handleother(Window *app);

//my_window.c
void draw_window(Window *app);
void del_window(Window *app);
void my_resize(Window *app);
void display_window(Window *app);

//main.c
int main(int ac, char **av);
int test_paint(Window *app);

//my_help.c
void get_help(void);

//my_write.c
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(const char *str);

//my_drawzone.C
void init_drawzone(Window *app);
void display_drawzone(Window *app);

//my_savetopng.c
void savedrawtoimage(sfRenderTexture *RenderTexture, const char *filePath);

//my_brush.c
void initbrush(Brush *brush, sfColor color, float radius);
void drawbrush(sfRenderTexture* renderTexture, Brush *brush, sfVector2f pos);
void create_line(Window *app);
void create_draw(Window *app);

//my_button.c
void updatebuttonstate(Button *button, sfRenderWindow *window);
void drawbutton(sfRenderWindow *window, Button *button);
void init_button(Button *Bouton);
void init_button2(void);

//my_handlekey.c
void keyp(Window *app);
void rightdraw(Window *app);
void stopdraw(Window *app);

//my_colors.c
void init_red(color_s *colors);
void display_color(color_s *colors, Window *app);

#endif /*PAINT*/
