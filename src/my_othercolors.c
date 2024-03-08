#include "../include/paint.h"

void init_blue(color_s *colors)
{
    colors->blue.color = sfSprite_create();
    colors->blue.x = 930;
    colors->blue.y = 85;
    colors->blue.color_texture = sfTexture_createFromFile(
                                "assets/colors/blue.png", NULL);
    colors->blue.colorect = (sfIntRect){0, 0, 15, 15};
    sfSprite_setTexture(colors->blue.color, colors->blue.color_texture,
                        sfTrue);
    sfSprite_setTextureRect(colors->blue.color, colors->blue.colorect);
    sfSprite_setPosition(colors->blue.color, (sfVector2f){colors->blue.x,
                        colors->blue.y});
}

void init_white(color_s *colors)
{
    colors->white.color = sfSprite_create();
    colors->white.x = 930;
    colors->white.y = 70;
    colors->white.color_texture = sfTexture_createFromFile(
                                "assets/white/blue.png", NULL);
    colors->white.colorect = (sfIntRect){0, 0, 15, 15};
    sfSprite_setTexture(colors->white.color, colors->white.color_texture,
                        sfTrue);
    sfSprite_setTextureRect(colors->white.color, colors->white.colorect);
    sfSprite_setPosition(colors->white.color, (sfVector2f){colors->white.x,
                        colors->white.y});
}


void init_black(color_s *colors)
{
    colors->black.color = sfSprite_create();
    colors->black.x = 930;
    colors->black.y = 85;
    colors->black.color_texture = sfTexture_createFromFile(
                                "assets/colors/black.png", NULL);
    colors->black.colorect = (sfIntRect){0, 0, 15, 15};
    sfSprite_setTexture(colors->black.color, colors->black.color_texture,
                        sfTrue);
    sfSprite_setTextureRect(colors->black.color, colors->black.colorect);
    sfSprite_setPosition(colors->black.color, (sfVector2f){colors->black.x,
                        colors->black.y});
}
