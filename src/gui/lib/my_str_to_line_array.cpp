/*
** EPITECH PROJECT, 2022
** my_str_to_line_array
** File description:
** tool
*/

#include <iostream>
#include <vector>

int nb_line(char *str)
{
    int nb_lines = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == '\n') {
            nb_lines = nb_lines + 1;
            i++;
        }
    }
    nb_lines++;
    return nb_lines;
}

int my_strlen2(char *str, int nb)
{
    int i = 1;

    while (str[nb + i] != '\0' && str[nb + i] != '\n') {
        i++;
    }
    return i;
}

std::vector<std::string> my_str_to_line_array(char *str)
{
    int nb_lines = nb_line(str);
    int i = 0;
    int y = 0;
    std::vector<std::string> pString;
    while (y < nb_lines) {
        while (str[i] != '\n' && str[i] != '\0') {
            std::string line;
            while (str[i] != '\n' && str[i] != '\0') {
                line += str[i];
                i++;
            }
            pString.push_back(line);
            y++;
        }
        i++;
    }
    return pString;
}
