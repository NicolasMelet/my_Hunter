/*
** EPITECH PROJECT, 2022
** My strmpc
** File description:
** Return 0 if str 1 and str 2 are equal,
** -1 if str 1 is lesser than str 2
** and 1 if str 1 is bigger than str 2
*/

int my_strlen(char const *str);

int verif_verdict(int i, int *verdict, char const *s1, char const *s2)
{
    if (s1[i] < s2[i]) {
        *verdict = -1;
    } else if (s1[i] > s2[i]) {
        *verdict = 1;
    } else {
        *verdict = 0;
    }
}

int my_strcmp(char const *s1 ,char const *s2)
{
    int i = 0;
    int verdict = -2;

    while (s1[i] != '\0' && s2[i] != '\0' && (verdict == -2 || verdict == 0)) {
        verif_verdict(i, &verdict, s1, s2);
        i += 1;
    }
    if (verdict >= -1 && verdict <= 1) {
        return (verdict);
    } else if (my_strlen(s1) < my_strlen(s2)) {
        return (-1);
    }
    return (1);
}
