/*
** EPITECH PROJECT, 2024
** my_event
** File description:
** switch case for my_paint
*/

#include "../include/paint.h"

int analyse_event(Window *app)
{
    while (sfRenderWindow_pollEvent(app->window, &app->event)) {
        switch (app->event.type){
            case sfEvtClosed:
        sfRenderWindow_close(app->window);
            break;
            case sfEvtKeyPressed:
                if (app->event.key.code == sfKeyP)
                savedrawtopng(app->drawzone, "dessin.png");
            break;
            case sfEvtMouseButtonPressed:
                if (app->event.mouseButton.button == sfMouseRight)
                    app->isDrawing = true;
            break;
            case sfEvtMouseButtonReleased:
                if (app->event.mouseButton.button == sfMouseRight)
                    app->isDrawing = false;
            break;
            case sfEvtMouseMoved:
                if (app->isDrawing) {
                    create_line(app);
                }
            break;
            case sfEvtResized:
                my_resize(app);
                    break;
            default:
                break;
        }
    }
    return 0;
}
