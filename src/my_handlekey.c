#include "../include/paint.h"

void keyp(Window *app)
{
    if (app->event.key.code == sfKeyP)
                savedrawtopng(app->drawzone, "dessin.png");
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
