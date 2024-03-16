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
    #include <math.h>

typedef enum {
    BRUSH,
    ERASER
} Tool;

typedef enum {
    BTN_IDLE,
    BTN_HOVER,
    BTN_PRESSED
} ButtonState;

typedef struct {
    sfRectangleShape *shape;
    ButtonState state;
    sfText* label;
    bool isVisible;
    bool wasPressed;
} Button;

typedef struct window {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfTexture *bgtexture;
    sfSprite *bgsprite;
    sfRenderTexture *drawzone;
    bool isDrawing;
    bool displayRoue;
    Tool current;
    sfSprite *palette;
    sfSprite *roue;
    sfSprite *SHelp;
    sfTexture *THelp;
    sfImage *image;
    sfTexture *Tpalette;
    sfTexture *Troue;
    sfColor selectedColor;
    Button boutonSaveAs;
    Button boutonPNG;
    Button boutonJPG;
    Button boutonBMP;
    bool dropdownVisible;
    sfSprite *image1;
    sfSprite *image2;
    bool showImages;
} Window;

typedef struct help {
    sfText *text;
    sfFont *font;
} Help;

typedef struct font {
    Help help;
    sfText *text;
    sfFont *font;
} Font;


typedef struct brush {
    sfColor color;
    float radius;
    sfVector2f lastPosition;
} Brush;

//my_event.c
void analyse_event(Window *app, Brush *brush);
void handlemouse(Window *app, Brush *brush);
void handleother(Window *app);


//my_window.c
void draw_window(Window *app);
void del_window(Window *app);
void my_resize(Window *app);
void display_window(Window *app);
void delete_all(Window *app);

//main.c
int main(int ac, char **av);
int test_paint(Window *app, Brush *brush, Font *font, Button *button);
void exec_paint(Window *app, Brush *brush, Font *font);
void exec_button(Window *app, Font *font);

//my_help.c
void get_help(void);

//my_write.c
void my_putchar(char c);
int my_strlen(const char *str);
void my_putstr(const char *str);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, char const *src);

//my_drawzone.C
void init_drawzone(Window *app);
void display_drawzone(Window *app);

//my_savetopng.c
int savedrawtoimage(sfRenderTexture *RenderTexture, const char *filePath);
void handlejpgclick(Window *app);
void handlebmpclick(Window *app);

//my_brush.c
void init_brush(Brush *brush, sfColor color, float radius);
void draw_brush(sfRenderTexture* renderTexture, Brush *brush, sfVector2f pos);
void create_line(Window *app, Brush *brush);
void create_draw(Window *app, Brush *brush);
void handle_palett(Window* app, Brush *brush);

//my_button.c
void updatebuttonstate(Button *button, Window *app, Font *font);
void drawbutton(Window *app, Button *button);
void initbutton(Button *button, sfVector2f position, sfVector2f size);
void handle_buttons(Window *app, Font *font);
void setup_buttons(Window *app, sfFont *font);

//handle_actions.c
void handle_buttons(Window *app, Font *font);
void handlebuttonhover(Button *button, sfVector2i mousePos);
void handleclickaction(Button *button, Window *app, Font *font);
void initbuttontext(Button *button, const char *text, sfFont *font);
void destroybutton(Button *button);

//draw_button.c
void drawbuttontext(Window *app, Button *button);
void drawbuttonshape(Window *app, Button *button);
void handle_primhelp(Window *app, Brush *brush, Font *font);

//my_about.c
void my_about(void);
void my_help(void);

//my_handlekey.c
void keyp(Window *app);
void rightdraw(Window *app);
void stopdraw(Window *app);

//init_images.c
void initimages(Window *app);

//init_tools.c
int init_tools(Window *app);
void display_elements(Window *app);
int opennewwindow(const char *message, Font *font);
void init(Font *font, Brush *brush, Window *app);
int init_tools2(Window *app);

#endif /*PAINT*/
