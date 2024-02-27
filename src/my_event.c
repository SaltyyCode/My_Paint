/*
** EPITECH PROJECT, 2024
** my_event
** File description:
** switch case for my_paint
*/

#include "../include/paint.h"

void handlemouse(Window *app)
{
    switch (app->event.type){
        case sfEvtMouseButtonPressed:
            rightdraw(app);
            break;
        case sfEvtMouseButtonReleased:
            stopdraw(app);
            break;
        case sfEvtMouseMoved:
            create_draw(app);
            break;
        default:
            break;
    }
}

void handleother(Window *app)
{
    switch (app->event.type){
        case sfEvtClosed:
            sfRenderWindow_close(app->window);
            break;
        case sfEvtKeyPressed:
            keyp(app);
            break;
        case sfEvtResized:
            my_resize(app);
            break;
        default:
            break;
    }
}