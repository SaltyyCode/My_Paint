/*
** EPITECH PROJECT, 2024
** my_pen
** File description:
** pen functions for my_paint
*/

#include "../include/paint.h"

void initbrush(Brush *brush, sfColor color, float radius)
{
    brush->color = color;
    brush->radius = radius;
}

void drawbrush(sfRenderTexture* renderTexture, Brush *brush, sfVector2f pos)
{
    sfCircleShape* shape = sfCircleShape_create();

    sfCircleShape_setRadius(shape, brush->radius);
    sfCircleShape_setFillColor(shape, brush->color);
    sfCircleShape_setPosition(shape, pos);
    sfRenderTexture_drawCircleShape(renderTexture, shape, NULL);
    sfRenderTexture_display(renderTexture);
    sfCircleShape_destroy(shape);
}
