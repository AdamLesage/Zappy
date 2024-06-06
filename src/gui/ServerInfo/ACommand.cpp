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

// Order: parsedData, size_map, tiles, players, eggs
void Zappy::ACommand::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    // Doesnt do anything
    (void)parsedData;
    (void)size_map;
    (void)tiles;
    (void)players;
    (void)eggs;
}
