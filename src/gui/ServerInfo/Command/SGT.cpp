/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SGT
*/

#include "SGT.hpp"

Zappy::SGT::SGT()
{
}

Zappy::SGT::~SGT()
{
}

void Zappy::SGT::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw Zappy::CommandError("Invalid number of arguments for SGT command", "SGT");
    std::string message = "sgt\n";
    write(fd, message.c_str(), message.size());
}

void Zappy::SGT::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int &timeUnit,
                                bool &isRunning
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)players; // unused
    (void)eggs; // unused
    (void)timeUnit; // unused
    (void)isRunning; // unused
    (void)teams; // unused
    // parsedData vector { "sgt", "timeUnit" }

    if (parsedData.size() != 2)
        throw Zappy::CommandError("Invalid number of arguments for SGT command", "SGT");

    try {
        timeUnit = std::stoi(parsedData[1]);
    } catch (std::exception &e) {
        throw Zappy::CommandError("Invalid arguments for SGT command", "SGT");
    }
}
