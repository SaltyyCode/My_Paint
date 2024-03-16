/*
** EPITECH PROJECT, 2024
** my_event
** File description:
** switch case for my_paint
*/

#include "../../include/paint.h"

static void onclickimage(Window *app)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(app->window);
    sfFloatRect image1 = sfSprite_getGlobalBounds(app->image1);
    sfFloatRect image2 = sfSprite_getGlobalBounds(app->image2);

    if (sfFloatRect_contains(&image1, mousePos.x, mousePos.y)) {
        my_help();
        app->showImages = false;
    }
    if (sfFloatRect_contains(&image2, mousePos.x, mousePos.y)) {
        my_about();
        app->showImages = false;
    }
}

void handlespriteclick(Window *app, sfSprite *sprite, Font *font)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(app->window);
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&spriteBounds, mousePos.x, mousePos.y)) {
        if (sprite == app->SHelp) {
            app->showImages = !app->showImages;
        }
    }
}

void handlemouse(Window *app, Brush *brush)
{
    Font font;

    switch (app->event.type) {
        case sfEvtMouseButtonPressed:
            handle_palett(app, brush);
            handlespriteclick(app, app->SHelp, &font);
            onclickimage(app);
            if (!app->displayRoue)
                app->isDrawing = true;
            break;
        case sfEvtMouseButtonReleased:
            app->isDrawing = false;
            break;
        case sfEvtMouseMoved:
            if (app->isDrawing)
                create_draw(app, brush);
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

void analyse_event(Window *app, Brush *brush)
{
    while (sfRenderWindow_pollEvent(app->window, &app->event)) {
        handlemouse(app, brush);
        handleother(app);
    }
}
