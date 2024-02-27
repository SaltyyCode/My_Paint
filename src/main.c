/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main function for my_paint
*/

#include "../include/paint.h"

int test_paint(Window *app)
{
    draw_window(app);
    init_drawzone(app);
    init_button(&bouton);
    init_button2();
    while (sfRenderWindow_isOpen(app->window)){
        analyse_event(app);
        display_window(app);
        display_drawzone(app);
        updatebuttonstate(&bouton, app->window);
        drawbutton(app->window, &bouton);
        updatebuttonstate(&bouton2, app->window);
        drawbutton(app->window, &bouton2);
        sfRenderWindow_display(app->window);
    }
    del_window(app);
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    Window *app = malloc(sizeof(Window));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        get_help();
        return 0;
    }
    test_paint(app);
    free(app);
    return 0;
}
