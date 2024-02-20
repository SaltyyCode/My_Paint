#include "../include/paint.h"

int main(int ac, char **av)
{
    Window *app = malloc(sizeof(Window));

    test_paint(app);
    free(app);
    return 0;
}