/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main function for my_paint
*/

#include "../include/paint.h"

int test_paint(Window *app, color_s *colors)
{
    draw_window(app);
    init_drawzone(app);
    init_button(&bouton);
    init_button2();
    init_red(colors);
    while (sfRenderWindow_isOpen(app->window)){
        analyse_event(app);
        display_window(app);
        display_drawzone(app);
        display_color(colors, app);
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
    color_s *colors = malloc(sizeof(color_s));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        get_help();
        return 0;
    }
    test_paint(app, colors);
    free(app);
    free(colors);
    return 0;
}
