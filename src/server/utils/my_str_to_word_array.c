/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Category: Utils | Convert a string to an array
 *
 * @param on_quote
 * @param c
 */
static void check_quote(bool *on_quote, char c)
{
    if (c == '"') {
        if (*on_quote) {
            *on_quote = false;
        } else {
            *on_quote = true;
        }
    }
}

/**
 * @brief Category: Utils | Convert a string to an array
 *
 * @param str
 * @param separator
 * @return int
 */
static int find_nb_separator(char *str, char separator)
{
    int nb_separator = 0;
    int i = 0;
    bool on_quote = false;

    for (i = 0; str[i] != '\0'; i++) {
        check_quote(&on_quote, str[i]);
        if (str[i] == separator && on_quote == false) {
            nb_separator++;
        }
    }
    if (str[i - 1] != separator) {
        nb_separator++;
    }
    return (nb_separator);
}

/**
 * @brief Category: Utils | Convert a string to an array
 *
 * @param str
 * @param separator
 * @param nb_separator
 * @return int*
 */
static int *find_nb_charaters(char *str, char separator, int nb_separator)
{
    int *nb_charaters = NULL;
    int index = 0;
    bool on_quote = false;

    nb_charaters = malloc(sizeof(int) * (nb_separator + 1));
    if (nb_charaters == NULL) {
        exit(84);
    }
    nb_charaters[index] = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        check_quote(&on_quote, str[i]);
        if (str[i] == separator && on_quote == false) {
            index++;
            nb_charaters[index] = 0;
        }
        nb_charaters[index]++;
    }
    return (nb_charaters);
}

/**
 * @brief Category: Utils | Convert a string to an array
 *
 * @param i
 * @param str
 * @param separator
 * @return int
 */
static int passe_separator(int i, char *str, char separator)
{
    while (str[i] == separator) {
        i++;
    }
    return (i);
}

/**
 * @brief Category: Utils | Convert a string to an array
 *
 * @param array
 * @param str
 * @param separator
 * @return char**
 */
static char **convert_str_to_array(char **array, char *str, char separator)
{
    int rows = 0;
    int cols = 0;
    bool on_quote = false;

    for (int i = 0; str[i] != '\0'; i++) {
        check_quote(&on_quote, str[i]);
        if (str[i] == separator && on_quote == false) {
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

/**
 * @brief Category: Utils | Convert a string to an array
 *
 * @param str
 * @param separator
 * @return char**
 */
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
