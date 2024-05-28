/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** int_to_str
*/

#include <stdlib.h>
#include <string.h>

char *revers_str(char *str, int i)
{
    char *new_str = malloc(sizeof(char) * 10);

    i--;
    for (int count = 0; str[count] != '\0'; i--) {
        new_str[count] = str[i];
        new_str[count + 1] = '\0';
        count++;
    }
    free(str);
    return (new_str);
}

char *int_to_str_neg_managment(int nbr_save, char *num_str, int *i)
{
    if (nbr_save < 0) {
        num_str[*i] = '-';
        num_str[*i + 1] = '\0';
        (*i)++;
    }
    return (num_str);
}

char *int_to_str(int nbr)
{
    int i = 0;
    int num = 0;
    int nbr_save = nbr;
    char *num_str = NULL;

    if (nbr == 0)
        return strdup("0");
    num_str = malloc(sizeof(char) * 11);
    if (nbr < 0)
        nbr = nbr * -1;
    for (; nbr >= 1; i++) {
        num = nbr % 10;
        num_str[i] = num + 48;
        num_str[i + 1] = '\0';
        nbr = nbr / 10;
    }
    num_str = int_to_str_neg_managment(nbr_save, num_str, &i);
    return (revers_str(num_str, i));
}
