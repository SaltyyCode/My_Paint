/*
** EPITECH PROJECT, 2024
** my_about
** File description:
** function for about section
*/

#include "../../include/paint.h"

void my_about(void)
{
    my_putstr("My_paint Epitech projet!\n");
    my_putstr("This is a reproduction of the famous paint software made by\n");
    my_putstr("Clement @SaltyyCode Bouret & Julien @Julienmarss Mars\n");
}

void my_help(void)
{
    my_putstr("\n Welcome to our paint ! heres how to use it:\n");
    my_putstr("Tools:\n");
    my_putstr("Eraser: Press E and click or drag to erase\n");
    my_putstr("After using the Eraser, press B and pick a Color!\n");
    my_putstr("Save as: Click on the button, select the format "
                "you want and write the name\n");
    my_putstr("of your filename in the terminal\n");
    my_putstr("Click on the pallet and click on the color you want\n");
}
