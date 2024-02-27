/*
** EPITECH PROJECT, 2024
** my_handlekey.c
** File description:
** //
*/

#include "../include/paint.h"

void keyp(Window *app)
{
    if (app->event.key.code == sfKeyP)
                savedrawtopng(app->drawzone, "dessin.png");
    if (app->event.key.code == sfKeyB)
                app->current = BRUSH;
    if (app->event.key.code == sfKeyE)
                app->current = ERASER;
}

void rightdraw(Window *app)
{
    if (app->event.mouseButton.button == sfMouseRight)
                    app->isDrawing = true;
}

void stopdraw(Window *app)
{
    if (app->event.mouseButton.button == sfMouseRight)
                    app->isDrawing = false;
}
