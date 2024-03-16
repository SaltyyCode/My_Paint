/*
** EPITECH PROJECT, 2024
** hadnle_actions.c
** File description:
** buttons actions
*/

#include "../../include/paint.h"

void drawbuttontext(Window *app, Button *button)
{
    sfVector2f shapePos = sfRectangleShape_getPosition(button->shape);
    sfVector2f shapeSize = sfRectangleShape_getSize(button->shape);
    sfFloatRect textRect = sfText_getLocalBounds(button->label);

    if (!button->isVisible)
        return;
    sfText_setPosition(button->label, (sfVector2f){
            shapePos.x + (shapeSize.x - textRect.width) / 2,
            shapePos.y + (shapeSize.y - textRect.height) / 2
    });
    sfRenderWindow_drawText(app->window,
                                button->label, NULL);
}

void drawbuttonshape(Window *app, Button *button)
{
    if (!button->isVisible)
        return;
    switch (button->state) {
        case BTN_IDLE:
            sfRectangleShape_setFillColor(button->shape,
                                            sfColor_fromRGB(100, 100, 200));
            break;
        case BTN_HOVER:
            sfRectangleShape_setFillColor(button->shape,
                                            sfColor_fromRGB(150, 150, 250));
            break;
        case BTN_PRESSED:
            sfRectangleShape_setFillColor(button->shape,
                                            sfColor_fromRGB(200, 200, 250));
            break;
    }
    sfRenderWindow_drawRectangleShape(app->window, button->shape, NULL);
}
