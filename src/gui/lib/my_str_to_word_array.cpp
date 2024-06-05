/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** tool
*/

#include <iostream>
#include <vector>

int nb_line(const char *str)
{
    int nb_lines = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == ' ') {
            nb_lines = nb_lines + 1;
            i++;
        }
    }
    nb_lines++;
    return nb_lines;
}

std::vector<std::string> my_str_to_word_array(const char *str)
{
    int nb_lines = nb_line(str);
    int i = 0;
    int y = 0;
    std::vector<std::string> pString;
    while (y < nb_lines) {
        while (str[i] != ' ' && str[i] != '\0') {
            std::string word;
            while (str[i] != ' ' && str[i] != '\0') {
                word += str[i];
                i++;
            }
            pString.push_back(word);
            y++;
        }
        i++;
    }
    return pString;
}
