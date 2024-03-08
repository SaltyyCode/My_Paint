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

void display_color(color_s* colors, Window *app)
{
    sfRenderWindow_drawSprite(app->window, colors->color, NULL);
    sfRenderWindow_drawSprite(app->window, colors->pink.color, NULL);
    sfRenderWindow_drawSprite(app->window, colors->yellow.color, NULL);
    sfRenderWindow_drawSprite(app->window, colors->green.color, NULL);
    sfRenderWindow_drawSprite(app->window, colors->blue.color, NULL);
    sfRenderWindow_drawSprite(app->window, colors->white.color, NULL);
    sfRenderWindow_drawSprite(app->window, colors->black.color, NULL);
}

void init_pink(color_s *colors)
{
    colors->pink.color = sfSprite_create();
    colors->pink.x = 900;
    colors->pink.y = 70;
    colors->pink.color_texture = sfTexture_createFromFile(
                                "assets/colors/pink.png", NULL);
    colors->pink.colorect = (sfIntRect){0, 0, 15, 15};
    sfSprite_setTexture(colors->pink.color, colors->pink.color_texture,
                        sfTrue);
    sfSprite_setTextureRect(colors->pink.color, colors->pink.colorect);
    sfSprite_setPosition(colors->pink.color, (sfVector2f){colors->pink.x,
                        colors->pink.y});
}

void init_yellow(color_s *colors)
{
    colors->yellow.color = sfSprite_create();
    colors->yellow.x = 915;
    colors->yellow.y = 85;
    colors->yellow.color_texture = sfTexture_createFromFile(
                                "assets/colors/yellow.png", NULL);
    colors->yellow.colorect = (sfIntRect){0, 0, 15, 15};
    sfSprite_setTexture(colors->yellow.color, colors->yellow.color_texture,
                        sfTrue);
    sfSprite_setTextureRect(colors->yellow.color, colors->yellow.colorect);
    sfSprite_setPosition(colors->yellow.color, (sfVector2f){colors->yellow.x,
                        colors->yellow.y});
}

void init_green(color_s *colors)
{
    colors->green.color = sfSprite_create();
    colors->green.x = 915;
    colors->green.y = 70;
    colors->green.color_texture = sfTexture_createFromFile(
                                "assets/colors/green.png", NULL);
    colors->green.colorect = (sfIntRect){0, 0, 15, 15};
    sfSprite_setTexture(colors->green.color, colors->green.color_texture,
                        sfTrue);
    sfSprite_setTextureRect(colors->green.color, colors->green.colorect);
    sfSprite_setPosition(colors->green.color, (sfVector2f){colors->green.x,
                        colors->green.y});
}