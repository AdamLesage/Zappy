/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str_to_word.h"

static int find_nb_separator(char *str, char separator)
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

static int *find_nb_charaters(char *str, char separator, int nb_separator)
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

static void passe_separator(int *i, char *str, char separator, int *row2)
{
    while (str[*i] == separator) {
        (*i)++;
        (*row2)++;
    }
    (*i)--;
    (*row2)--;
}

static void alloc_new_line(char **line, int *nb_charaters, int *row2)
{
    (*row2)++;
    free(*line);
    *line = NULL;
    *line = malloc(sizeof(char) * (nb_charaters[*row2] + 1));
}

static void set_line(char **line, int *cols, int i, char *str)
{
    (*line)[*cols] = str[i];
    (*cols)++;
    (*line)[*cols] = '\0';
}

static void init_convert_struct(convert_t *convert, int *nb_charaters)
{
    convert->rows = 0;
    convert->cols = 0;
    convert->row2 = 0;
    convert->nb_charaters = nb_charaters;
}

static char **loop_on_str(char separator, char *str, convert_t *convert,
    char **array)
{
    char *line = malloc(sizeof(char) * (convert->nb_charaters[0] + 1));

    line[0] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            passe_separator(&i, str, separator, &convert->row2);
            array[convert->rows] = strdup(line);
            array[convert->rows + 1] = NULL;
            convert->rows++;
            alloc_new_line(&line, convert->nb_charaters, &convert->row2);
            convert->cols = 0;
        } else
            set_line(&line, &convert->cols, i, str);
    }
    array[convert->rows] = NULL;
    if (line != NULL) {
        array[convert->rows + 1] = NULL;
    }
    free(line);
    return (array);
}

static char **convert_str_to_array(int nb_separator, char *str, char separator,
    int *nb_charaters)
{
    char **array = malloc(sizeof(char *) * (nb_separator + 2));
    convert_t convert;

    init_convert_struct(&convert, nb_charaters);
    array = loop_on_str(separator, str, &convert, array);
    return (array);
}

char **my_str_to_word_array(char *str, char separator)
{
    char **array = NULL;
    int nb_separator = 0;
    int *nb_charaters = 0;

    nb_separator = find_nb_separator(str, separator);
    nb_charaters = find_nb_charaters(str, separator, nb_separator);
    array = convert_str_to_array(nb_separator, str,
        separator, nb_charaters);
    free(nb_charaters);
    return (array);
}
