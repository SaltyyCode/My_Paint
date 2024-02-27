#include "../include/paint.h"

Button bouton;
Button bouton2;

void updatebuttonstate(Button *button, sfRenderWindow *window)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->shape);

    button->state = BTN_IDLE;
    if (sfFloatRect_contains(&bounds, (float)mousePos.x, (float)mousePos.y)) {
        button->state = BTN_HOVER;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            button->state = BTN_PRESSED;
        }
    }
}

void drawbutton(sfRenderWindow *window, Button *button)
{
    switch (button->state) {
        case BTN_IDLE:
            sfRectangleShape_setFillColor(button->shape,
            sfColor_fromRGB(100, 100, 200));
            break;
        case BTN_HOVER:
            sfRectangleShape_setFillColor(button->shape,
            sfColor_fromRGB(150, 150, 250));
            break;
        case BTN_PRESSED:
            sfRectangleShape_setFillColor(button->shape,
            sfColor_fromRGB(200, 200, 250));
            break;
    }
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
}

void init_button(Button *Bouton)
{
    Bouton->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(Bouton->shape, (sfVector2f){200, 50});
    sfRectangleShape_setPosition(Bouton->shape, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(Bouton->shape, sfColor_fromRGB(255, 0, 0));
    Bouton->state = BTN_IDLE;
}

void init_button2()
{
    bouton2.shape = sfRectangleShape_create();
    sfRectangleShape_setSize(bouton2.shape, (sfVector2f){200, 50});
    sfRectangleShape_setPosition(bouton2.shape, (sfVector2f){200,50});
    sfRectangleShape_setFillColor(bouton2.shape, sfColor_fromRGB(0, 255, 0));
    bouton2.state = BTN_IDLE;
}
