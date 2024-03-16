/*
** EPITECH PROJECT, 2024
** my_brush
** File description:
** init brush and brush functions for my_paint
*/

#include "../../include/paint.h"

void init_brush(Brush *brush, sfColor color, float radius)
{
    brush->color = color;
    brush->radius = radius;
}

void draw_brush(sfRenderTexture* renderTexture, Brush *brush, sfVector2f pos)
{
    sfCircleShape* shape = sfCircleShape_create();

    sfCircleShape_setRadius(shape, brush->radius);
    sfCircleShape_setFillColor(shape, brush->color);
    sfCircleShape_setPosition(shape, pos);
    sfRenderTexture_drawCircleShape(renderTexture, shape, NULL);
    sfRenderTexture_display(renderTexture);
    sfCircleShape_destroy(shape);
}

void create_line(Window *app, Brush *brush)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(app->window);
    sfVector2f position = {mousePos.x, mousePos.y - 100};

    if (app->current == BRUSH) {
        init_brush(brush, brush->color, brush->radius);
    } else if (app->current == ERASER) {
        init_brush(brush, sfWhite, brush->radius);
    }
    draw_brush(app->drawzone, brush, position);
}

void create_draw(Window *app, Brush *brush)
{
    if (app->isDrawing) {
        create_line(app, brush);
    }
}

static void handleroueclick(Window* app, sfVector2i mousePos, Brush *brush)
{
    sfVector2f rouePosition = sfSprite_getPosition(app->roue);
    sfVector2u pixelPos = {
            mousePos.x - (unsigned int)rouePosition.x,
            mousePos.y - (unsigned int)rouePosition.y
    };
    sfVector2u imageSize = sfImage_getSize(app->image);

    if (pixelPos.x < imageSize.x && pixelPos.y < imageSize.y) {
        brush->color = sfImage_getPixel(app->image, pixelPos.x, pixelPos.y);
        app->displayRoue = false;
    }
}

void handle_palett(Window* app, Brush *brush)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(app->window);
    sfFloatRect boundsPalette = sfSprite_getGlobalBounds(app->palette);
    sfFloatRect boundsRoue = sfSprite_getGlobalBounds(app->roue);

    if (sfFloatRect_contains(&boundsPalette, mousePosition.x,
                                mousePosition.y)) {
        app->displayRoue = !app->displayRoue;
    } else if (app->displayRoue && sfFloatRect_contains(&boundsRoue,
                                                        mousePosition.x,
                                                        mousePosition.y)) {
        handleroueclick(app, mousePosition, brush);
    }
}
