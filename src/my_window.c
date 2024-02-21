#include "../include/paint.h"

void draw_window(Window *app)
{
    app->video_mode.width = 1080;
    app->video_mode.height = 1920;
    app->video_mode.bitsPerPixel = 32;
    app->window = sfRenderWindow_create(app->video_mode,
    "My_Paint", sfResize | sfClose, NULL);

}

void display_window(Window *app)
{
    sfRenderWindow_clear(app->window, sfBlack);
}

void del_window(Window *app)
{
    if (app->drawzone != NULL)
        sfRenderTexture_destroy(app->drawzone);
    sfRenderWindow_destroy(app->window);
}

int test_paint(Window *app)
{
    draw_window(app);
    init_drawzone(app);
    while (sfRenderWindow_isOpen(app->window)){
        analyse_event(app);
        display_window(app);
        display_drawzone(app);
        sfRenderWindow_display(app->window);
    }
    del_window(app);
    return EXIT_SUCCESS;
}