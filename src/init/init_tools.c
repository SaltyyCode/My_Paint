/*
** EPITECH PROJECT, 2024
** init_tools
** File description:
** create all the sprite and texture for my tools colors
*/

#include "../../include/paint.h"

int init_tools(Window *app)
{
    sfVector2u PaletteSize;
    sfVector2f palettePosition;
    sfVector2f rouePosition;

    app->Tpalette = sfTexture_createFromFile("assets/palette.png", NULL);
    app->image = sfImage_createFromFile("assets/Roue-chromatique.png");
    app->Troue = sfTexture_createFromImage(app->image, NULL);
    if (!app->image || !app->Tpalette || !app->Troue)
        return 84;
    app->palette = sfSprite_create();
    app->roue = sfSprite_create();
    sfSprite_setTexture(app->palette, app->Tpalette, sfTrue);
    PaletteSize = sfTexture_getSize(app->Tpalette);
    palettePosition = (sfVector2f){app->video_mode.width - PaletteSize.x, 0};
    sfSprite_setPosition(app->palette, palettePosition);
    sfSprite_setTexture(app->roue, app->Troue, sfTrue);
    rouePosition = (sfVector2f){palettePosition.x - 150, PaletteSize.y};
    sfSprite_setPosition(app->roue, rouePosition);
    app->displayRoue = false;
    return 0;
}

int init_tools2(Window *app)
{
    sfVector2u windowSize;
    sfVector2u imageSize;
    sfVector2f position;

    app->THelp = sfTexture_createFromFile("assets/aide.png", NULL);
    if (!app->THelp)
        return 84;
    app->SHelp = sfSprite_create();
    sfSprite_setTexture(app->SHelp, app->THelp, sfTrue);
    windowSize = sfRenderWindow_getSize(app->window);
    imageSize = sfTexture_getSize(app->THelp);
    position = (sfVector2f){ (windowSize.x - imageSize.x) / 2.0f, 0 };
    sfSprite_setPosition(app->SHelp, position);
    return 0;
}

void display_elements(Window *app)
{
    display_drawzone(app);
    sfRenderWindow_drawSprite(app->window, app->palette, NULL);
    if (app->displayRoue) {
        sfRenderWindow_drawSprite(app->window, app->roue, NULL);
    }
    if (app->showImages) {
        sfRenderWindow_drawSprite(app->window, app->image1, NULL);
        sfRenderWindow_drawSprite(app->window, app->image2, NULL);
    }
}

void init(Font *font, Brush *brush, Window *app)
{
    brush->color = sfRed;
    brush->radius = 5;
    app->isDrawing = false;
    app->dropdownVisible = false;
    font->help.text = sfText_create();
    font->font = sfFont_createFromFile("assets/fonts/arial.ttf");
    font->text = sfText_create();
    font->help.font = sfFont_createFromFile("assets/fonts/arial.ttf");
    sfText_setFont(font->text, font->font);
}

void destroybutton(Button *button)
{
    sfRectangleShape_destroy(button->shape);
    sfText_destroy(button->label);
}
