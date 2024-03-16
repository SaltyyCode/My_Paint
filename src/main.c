/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main function for my_paint
*/

#include "../include/paint.h"

void exec_paint(Window *app, Brush *brush, Font *font)
{
    analyse_event(app, brush);
        display_window(app);
        display_elements(app);
        sfRenderWindow_drawSprite(app->window, app->SHelp, NULL);
        handle_buttons(app, font);
        sfRenderWindow_display(app->window);
}

void exec_button(Window *app, Font *font)
{
    updatebuttonstate(&app->boutonSaveAs, app, font);
    drawbutton(app, &app->boutonSaveAs);
    if (app->boutonPNG.isVisible) {
        updatebuttonstate(&app->boutonPNG, app, font);
        drawbutton(app, &app->boutonPNG);
    }
    if (app->boutonJPG.isVisible) {
        updatebuttonstate(&app->boutonJPG, app, font);
        drawbutton(app, &app->boutonJPG);
    }
    if (app->boutonBMP.isVisible) {
        updatebuttonstate(&app->boutonBMP, app, font);
        drawbutton(app, &app->boutonBMP);
    }
}

int test_paint(Window *app, Brush *brush, Font *font, Button *button)
{
    init(font, brush, app);
    draw_window(app);
    initimages(app);
    if (init_tools(app) != 0 || init_tools2(app) != 0)
        return 84;
    init_drawzone(app);
    setup_buttons(app, font->font);
    while (sfRenderWindow_isOpen(app->window)) {
        exec_button(app, font);
        exec_paint(app, brush, font);
    }
    destroybutton(button);
    delete_all(app);
    del_window(app);
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    Window *app = malloc(sizeof(Window));
    Brush *brush = malloc(sizeof(Brush));
    Font *font = malloc(sizeof(Font));
    Button *button = malloc(sizeof(Button));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        get_help();
        return 0;
    }
    test_paint(app, brush, font, button);
    free(app);
    free(brush);
    free(font);
    free(button);
    return 0;
}
