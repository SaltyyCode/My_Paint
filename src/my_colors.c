/*
** EPITECH PROJECT, 2024
** my_colors.c
** File description:
** functions for colors in paint
*/

#include "../include/paint.h"

void init_red(color_s *colors)
{
    colors->color = sfSprite_create();
    colors->x = 900;
    colors->y = 85;
    colors->color_texture = sfTexture_createFromFile("assets/colors/red.png",
                            NULL);
    colors->colorect = (sfIntRect){0, 0, 15, 15};
    sfSprite_setTexture(colors->color, colors->color_texture, sfTrue);
    sfSprite_setTextureRect(colors->color, colors->colorect);
    sfSprite_setPosition(colors->color, (sfVector2f){colors->x, colors->y});
}

void display_color(color_s *colors, Window *app)
{
    sfRenderWindow_drawSprite(app->window, colors->color, NULL);
}
