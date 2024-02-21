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
                    savedrawtopng(app->drawzone, "dessin.jpg");
            break;
                case sfEvtMouseButtonPressed:
                    if (app->event.mouseButton.button == sfMouseRight) {
                        sfVector2i mousePos = sfMouse_getPositionRenderWindow(app->window);
                        sfVector2f position = {mousePos.x, mousePos.y - 100};
                        Brush brush;
                        initbrush(&brush, sfRed, 5);
                        drawbrush(app->drawzone, &brush, position);
                     }
                    break;
            default:
                break;
        }
    }
    return 0;
}