/*
** EPITECH PROJECT, 2024
** my_savetopng.c
** File description:
** function to save drawing in my_paint
*/

#include "../../include/paint.h"

int savedrawtoimage(sfRenderTexture *RenderTexture, const char *filePath)
{
    const sfTexture* textureDessin;
    sfImage *image;

    if (!RenderTexture || !filePath)
        return 84;
    textureDessin = sfRenderTexture_getTexture(RenderTexture);
    image = sfTexture_copyToImage(textureDessin);
    sfImage_saveToFile(image, filePath);
    sfImage_destroy(image);
    return 0;
}

void handlejpgclick(Window *app)
{
    char *filename = NULL;
    size_t bufsize = 0;
    size_t len = 0;
    char filepath[260];

    my_putstr("Enter the filename to save the image (with .jpg extension): ");
    getline(&filename, &bufsize, stdin);
    len = my_strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    my_strcpy(filepath, filename);
    my_strcat(filepath, ".jpg");
    savedrawtoimage(app->drawzone, filepath);
    free(filename);
}

void handlebmpclick(Window *app)
{
    char *filename = NULL;
    size_t bufsize = 0;
    size_t len = 0;
    char filepath[260];

    my_putstr("Enter the filename to save the image (with .bmp extension): ");
    getline(&filename, &bufsize, stdin);
    len = my_strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    my_strcpy(filepath, filename);
    my_strcat(filepath, ".bmp");
    savedrawtoimage(app->drawzone, filepath);
    free(filename);
}
