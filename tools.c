/*
** EPITECH PROJECT, 2022
** tools
** File description:
** tools
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        my_putnbr(nb);
    } else if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else {
        my_putchar(nb + 48);
    }
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i += 1;
    }
    return (i);
}
