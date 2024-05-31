/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

int find_nb_separator(char *str, char separator)
{
    int nb_separator = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            nb_separator++;
        }
    }
    if (str[i - 1] != separator) {
        nb_separator++;
    }
    return (nb_separator);
}

int *find_nb_charaters(char *str, char separator, int nb_separator)
{
    int *nb_charaters = NULL;
    int index = 0;

    nb_charaters = malloc(sizeof(int) * (nb_separator + 1));
    if (nb_charaters == NULL) {
        exit(84);
    }
    nb_charaters[index] = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            index++;
            nb_charaters[index] = 0;
        }
        nb_charaters[index]++;
    }
    return (nb_charaters);
}

int passe_separator(int i, char *str, char separator)
{
    while (str[i] == separator) {
        i++;
    }
    return (i);
}

char **convert_str_to_array(char **array, char *str, char separator)
{
    int rows = 0;
    int cols = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            i = passe_separator(i, str, separator);
            i--;
            rows++;
            cols = 0;
        } else {
            array[rows][cols] = str[i];
            cols++;
            array[rows][cols] = '\0';
        }
    }
    return (array);
}

char **my_str_to_word_array(char *str, char separator)
{
    char **array = NULL;
    int nb_separator = 0;
    int *nb_charaters = 0;

    nb_separator = find_nb_separator(str, separator);
    nb_charaters = find_nb_charaters(str, separator, nb_separator);
    array = malloc(sizeof(char *) * (nb_separator + 1));
    if (array == NULL) {
        exit(84);
    }
    for (int i = 0; i != nb_separator; i++) {
        array[i] = malloc(sizeof(char) * (nb_charaters[i] + 1));
        if (array[i] == NULL) {
            exit(84);
        }
        array[i + 1] = NULL;
    }
    free(nb_charaters);
    array = convert_str_to_array(array, str, separator);
    return (array);
}
