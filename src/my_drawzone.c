/*
** EPITECH PROJECT, 2024
** my_drawzone
** File description:
** drawzone functions for my_paint
*/

#include "../include/paint.h"

void init_drawzone(Window *app)
{
    const int reserved = 100;

    app->drawzone = sfRenderTexture_create(app->video_mode.width,
    app->video_mode.height - reserved, false);
    sfRenderTexture_clear(app->drawzone, sfWhite);
    sfRenderTexture_display(app->drawzone);
}

void display_drawzone(Window *app)
{
    const sfTexture* texture = sfRenderTexture_getTexture(app->drawzone);
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 100});
    sfRenderWindow_drawSprite(app->window, sprite, NULL);
    sfSprite_destroy(sprite);
}
