/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ICommand
*/

#ifndef ICOMMAND_HPP_
#define ICOMMAND_HPP_

#include <iostream>
#include <vector>
#include <string.h>
#include <unistd.h>

std::vector<std::string> my_str_to_word_array(const char *str);
std::vector<std::string> my_str_to_line_array(char *str);

class ICommand {
    public:
        virtual ~ICommand() = default;

        virtual void askCommand(int socket, std::vector<std::string> args) = 0;
    protected:
    private:
};

#endif /* !ICOMMAND_HPP_ */
