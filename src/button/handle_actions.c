/*
** EPITECH PROJECT, 2024
** hadnle_actions.c
** File description:
** buttons actions
*/

#include "../../include/paint.h"
#include <string.h>

void initbuttontext(Button *button, const char *text, sfFont *font)
{
    button->label = sfText_create();
    sfText_setString(button->label, text);
    sfText_setFont(button->label, font);
}

void handle_buttons(Window *app, Font *font)
{
    updatebuttonstate(&app->boutonSaveAs, app, font);
    drawbutton(app, &app->boutonSaveAs);
    if (app->boutonPNG.isVisible) {
        updatebuttonstate(&app->boutonPNG, app, font);
        drawbutton(app, &app->boutonPNG);
        updatebuttonstate(&app->boutonJPG, app, font);
        drawbutton(app, &app->boutonJPG);
        updatebuttonstate(&app->boutonBMP, app, font);
        drawbutton(app, &app->boutonBMP);
    }
}

void handlebuttonhover(Button *button, sfVector2i mousePos)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->shape);

    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            button->state = BTN_PRESSED;
        } else {
            button->state = BTN_HOVER;
        }
    } else {
        button->state = BTN_IDLE;
    }
}

void handlepngclick(Window *app)
{
    char *filename = NULL;
    size_t bufsize = 0;
    size_t len = 0;
    char filepath[260];

    my_putstr("Enter the filename to save the image (with .png extension): ");
    getline(&filename, &bufsize, stdin);
    len = my_strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    my_strcpy(filepath, filename);
    my_strcat(filepath, ".png");
    savedrawtoimage(app->drawzone, filepath);
    free(filename);
}

void handleclickaction(Button *button, Window *app, Font *font)
{
    if (button->isVisible && button->state == BTN_PRESSED &&
        button->wasPressed) {
        if (button == &app->boutonPNG)
            handlepngclick(app);
        if (button == &app->boutonJPG)
            handlejpgclick(app);
        if (button == &app->boutonBMP)
            handlebmpclick(app);
        if (button == &app->boutonSaveAs) {
            app->dropdownVisible = !app->dropdownVisible;
            app->boutonPNG.isVisible = app->dropdownVisible;
            app->boutonJPG.isVisible = app->dropdownVisible;
            app->boutonBMP.isVisible = app->dropdownVisible;
        }
    }
    button->wasPressed = (button->state == BTN_PRESSED);
}
