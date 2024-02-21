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

typedef struct window {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfTexture *bgtexture;
    sfSprite *bgsprite;
    sfRenderTexture *drawzone;
} Window;

typedef struct brush {
    sfColor color;
    float radius;
} Brush;

//my_event.c
int analyse_event(Window *app);

//my_window.c
void draw_window(Window *app);
void del_window(Window *app);
int test_paint(Window *app);

//main.c
int main(int ac, char **av);

//my_help.c
void get_help();

//my_write.c
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(const char *str);

//my_drawzone.C
void init_drawzone(Window *app);
void display_drawzone(Window *app);

//my_savetopng.c
void savedrawtopng(sfRenderTexture* RenderTexture, const char* filePath);

//my_brush.c
void initbrush(Brush *brush, sfColor color, float radius);
void drawbrush(sfRenderTexture* renderTexture, Brush *brush, sfVector2f pos);

#endif /*PAINT*/