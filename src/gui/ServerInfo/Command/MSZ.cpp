/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MSZ
*/

#include "MSZ.hpp"

Zappy::MSZ::MSZ()
{
}

Zappy::MSZ::~MSZ()
{
}

void Zappy::MSZ::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments for SGT command");
    std::string message = "msz\n";
    write(fd, message.c_str(), message.size());
}

void Zappy::MSZ::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    (void)tiles; // unused
    (void)players; // unused
    (void)eggs; // unused

    if (parsedData.size() != 3)
        throw std::invalid_argument("Invalid number of arguments for SGT command");
    size_map[0] = std::stoi(parsedData[1]);
    size_map[1] = std::stoi(parsedData[2]);
}
