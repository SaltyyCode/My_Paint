#include "../include/paint.h"

int analyse_event(Window *app)
{

    while (sfRenderWindow_pollEvent(app->window, &app->event)) {
        switch (app->event.type){
            case sfEvtClosed:
                sfRenderWindow_close(app->window);
        }
    }
}