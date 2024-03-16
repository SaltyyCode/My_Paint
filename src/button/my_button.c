/*
** EPITECH PROJECT, 2024
** my_button.c
** File description:
** buttons fonctions
*/

#include "../../include/paint.h"

void updatebuttonstate(Button *button, Window *app, Font *font)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(app->window);

    handlebuttonhover(button, mousePos);
    handleclickaction(button, app, font);
    app->boutonPNG.isVisible = app->dropdownVisible;
    app->boutonJPG.isVisible = app->dropdownVisible;
    app->boutonBMP.isVisible = app->dropdownVisible;
}

void drawbutton(Window *app, Button *button)
{
    drawbuttonshape(app, &app->boutonSaveAs);
    drawbuttontext(app, &app->boutonSaveAs);
    drawbuttonshape(app, &app->boutonPNG);
    drawbuttontext(app, &app->boutonPNG);
    drawbuttonshape(app, &app->boutonJPG);
    drawbuttontext(app, &app->boutonJPG);
    drawbuttonshape(app, &app->boutonBMP);
    drawbuttontext(app, &app->boutonBMP);
}

void initbutton(Button *button, sfVector2f position, sfVector2f size)
{
    button->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(button->shape, size);
    sfRectangleShape_setPosition(button->shape, position);
    button->state = BTN_IDLE;
    button->isVisible = false;
}

void setup_buttons(Window *app, sfFont *font)
{
    sfVector2f buttonSize = {200, 50};

    initbutton(&app->boutonSaveAs, (sfVector2f) {50, 50}, buttonSize);
    initbutton(&app->boutonPNG, (sfVector2f) {50, 110}, buttonSize);
    initbutton(&app->boutonJPG, (sfVector2f) {50, 170}, buttonSize);
    initbutton(&app->boutonBMP, (sfVector2f) {50, 230}, buttonSize);
    initbuttontext(&app->boutonSaveAs, "Save As", font);
    initbuttontext(&app->boutonPNG, "PNG", font);
    initbuttontext(&app->boutonJPG, "JPG", font);
    initbuttontext(&app->boutonBMP, "BMP", font);
    app->boutonSaveAs.isVisible = true;
    app->boutonPNG.isVisible = false;
    app->boutonJPG.isVisible = false;
    app->boutonBMP.isVisible = false;
}
