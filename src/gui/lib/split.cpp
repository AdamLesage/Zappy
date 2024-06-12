/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** split
*/

#include <vector>
#include <string>

std::vector<std::string> split(std::string str, std::string separator)
{
    std::vector<std::string> array;
    std::string subStr;

    for (size_t i = 0; i != str.size() ; i++) {
        if (separator.find(str[i]) != separator.npos) {
            array.push_back(subStr);
            subStr.clear();
        } else {
            subStr.push_back(str[i]);
        }
    }
    return array;
}
