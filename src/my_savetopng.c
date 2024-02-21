#include "../include/paint.h"

void savedrawtopng(sfRenderTexture* RenderTexture, const char* filePath)
{
    const sfTexture* textureDessin;
    
    if (!RenderTexture || !filePath)
        return;
    textureDessin = sfRenderTexture_getTexture(RenderTexture);
    sfImage* image = sfTexture_copyToImage(textureDessin);
    sfImage_saveToFile(image, filePath);
    sfImage_destroy(image);

}