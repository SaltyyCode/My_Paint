/*
** EPITECH PROJECT, 2024
** my_write
** File description:
** write functions
*/

#include "../include/paint.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar('0' + nb);
    }
    if (nb <= 10){
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}

void my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
        }
}
