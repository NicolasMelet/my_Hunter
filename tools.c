/*
** EPITECH PROJECT, 2022
** tools
** File description:
** tools
*/
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i += 1;
    }
    return (i);
}

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);
    int i = 0;
    while (i <= len) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i += 1;
    }
    dest[len + i] = '\0';
    return (dest);
}

int intlen(int nbr)
{
    int i = 0;

    if (nbr < 0) {
        i += 1;
        nbr *= -1;
    }
    if (nbr == 0)
        return 1;
    while (nbr >= 1) {
        i += 1;
        nbr = nbr / 10;
    }
    return i;
}

char *int_to_str(int score)
{
    int len = intlen(score);
    char *nbr = malloc(len + 1);
    int i = 0;

    if (score == 0) {
        nbr[0] = '0';
        nbr[1] = '\0';
        return nbr;
    }
    while (score > 0) {
        nbr[len - 1 - i] = score % 10 + 48;
        score = score / 10;
        i += 1;
    }
    nbr[len] = '\0';
    return nbr;
}
