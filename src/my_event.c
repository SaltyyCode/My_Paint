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
                keyp(app);
            break;
            case sfEvtMouseButtonPressed:
                rightdraw(app);
            break;
            case sfEvtMouseButtonReleased:
                stopdraw(app);
            break;
            case sfEvtMouseMoved:
                create_draw(app);
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
