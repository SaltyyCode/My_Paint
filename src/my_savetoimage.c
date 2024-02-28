/*
** EPITECH PROJECT, 2024
** my_savetopng.c
** File description:
** function to save drawing in my_paint
*/

#include "../include/paint.h"

void savedrawtopng(sfRenderTexture *RenderTexture, const char *filePath)
{
    const sfTexture* textureDessin;
    sfImage *image;

    if (!RenderTexture || !filePath)
        return;
    textureDessin = sfRenderTexture_getTexture(RenderTexture);
    image = sfTexture_copyToImage(textureDessin);
    sfImage_saveToFile(image, filePath);
    sfImage_destroy(image);
}
