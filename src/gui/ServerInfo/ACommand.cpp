/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ACommand
*/

#include "ACommand.hpp"

Zappy::ACommand::ACommand()
{
}

Zappy::ACommand::~ACommand()
{
}

std::vector<std::string> Zappy::ACommand::receiveData(std::string message, std::string commandName)
{
    if (strncmp(message.c_str(), commandName.c_str(), commandName.size()))
        return {};

    std::vector<std::string> args = my_str_to_word_array(message.c_str());
    std::vector<std::string> data = { commandName };
    for (std::size_t i = 1; i < args.size(); i++)
        data.push_back(args[i]);
    return (data);
}

void Zappy::ACommand::askCommand(int socket, std::vector<std::string> args)
{
    if (args.size() == 0 || socket == -1)
        return;
}
