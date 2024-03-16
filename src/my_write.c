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

void my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
        }
}

int my_strlen(const char *str)
{
    int length = 0;

    if (str == NULL) {
        return 0;
    }
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strcpy(char *dest, char const *src)
{
    int nb = 0;

    while (src[nb] != '\0') {
        dest[nb] = src[nb];
        nb++;
    }
    return dest;
}
