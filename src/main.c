#include "../include/paint.h"

int main(int ac, char **av)
{
    Window *app = malloc(sizeof(Window));

    if(ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        get_help();
        return 0;
    }

    test_paint(app);
    free(app);
    return 0;
}