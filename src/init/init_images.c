/*
** EPITECH PROJECT, 2024
** init_tools
** File description:
** create all the sprite and texture for my tools colors
*/

#include "../../include/paint.h"

void setpositions(Window *app)
{
    sfVector2u windowSize = sfRenderWindow_getSize(app->window);
    sfVector2u image1Size = sfTexture_getSize(sfSprite_getTexture(
                app->image1));
    sfVector2u image2Size = sfTexture_getSize(sfSprite_getTexture(
                app->image2));
    sfVector2f position1 = {(windowSize.x - image1Size.x) / 2.0f,
                                (windowSize.y - image1Size.y) / 8.0f};
    sfVector2f position2 = {(windowSize.x - image2Size.x) / 2.0f,
                            (windowSize.y - image2Size.y) / 8.0f
                                + image1Size.y};

    sfSprite_setPosition(app->image1, position1);
    sfSprite_setPosition(app->image2, position2);
    app->showImages = false;
}

void initimages(Window *app)
{
    sfTexture *texture1 = sfTexture_createFromFile("assets/help.png", NULL);
    sfTexture *texture2 = sfTexture_createFromFile("assets/about.png", NULL);

    app->image1 = sfSprite_create();
    app->image2 = sfSprite_create();
    sfSprite_setTexture(app->image1, texture1, sfTrue);
    sfSprite_setTexture(app->image2, texture2, sfTrue);
    setpositions(app);
}
