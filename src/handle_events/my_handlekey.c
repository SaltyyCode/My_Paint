/*
** EPITECH PROJECT, 2024
** my_handlekey.c
** File description:
** //
*/

#include "../../include/paint.h"

void keyp(Window *app)
{
    if (app->event.key.code == sfKeyP)
        savedrawtoimage(app->drawzone, "dessin.png");
    if (app->event.key.code == sfKeyM)
        savedrawtoimage(app->drawzone, "dessin.jpg");
    if (app->event.key.code == sfKeyO)
        savedrawtoimage(app->drawzone, "dessin.bmp");
    if (app->event.key.code == sfKeyE)
        app->current = ERASER;
    if (app->event.key.code == sfKeyB)
        app->current = BRUSH;
}
