/*
** EPITECH PROJECT, 2024
** my_window
** File description:
** create display and destroy window for my_paint
*/

#include "../../include/paint.h"

void draw_window(Window *app)
{
    app->video_mode.width = 1920;
    app->video_mode.height = 1080;
    app->video_mode.bitsPerPixel = 32;
    app->window = sfRenderWindow_create(app->video_mode,
    "My_Paint", sfResize | sfClose, NULL);
    app->isDrawing = false;
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

void my_resize(Window *app)
{
    sfView* view = sfView_createFromRect((sfFloatRect){0, 0,
    app->event.size.width, app->event.size.height});

    sfRenderWindow_setView(app->window, view);
}

void delete_all(Window *app)
{
    sfSprite_destroy(app->bgsprite);
    sfSprite_destroy(app->palette);
    sfSprite_destroy(app->roue);
    sfSprite_destroy(app->SHelp);
    sfSprite_destroy(app->image1);
    sfSprite_destroy(app->image2);
    sfTexture_destroy(app->bgtexture);
    sfTexture_destroy(app->THelp);
    sfTexture_destroy(app->Tpalette);
    sfTexture_destroy(app->Troue);
}
