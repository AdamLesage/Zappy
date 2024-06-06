/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIE
*/

#include "PIE.hpp"

Zappy::PIE::PIE()
{
}

Zappy::PIE::~PIE()
{
}

void Zappy::PIE::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "pie " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}

void Zappy::PIE::applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
)
{
    (void)size_map; // unused
    (void)tiles; // unused
    (void)eggs; // unused
    // parsedData vector { "pie", "x", "y", "incantation result" }
    if (parsedData.size() < 5)
        throw std::invalid_argument("Invalid number of arguments for PIC command");

    try {
        // Update player isIncanting status
        std::string incantationResult = parsedData[3];
        for (auto &player : players) {
            for (std::size_t i = 4; i < parsedData.size(); i++) {
                if (player.get()->getPlayerNumber() == std::stoi(parsedData[i])) {
                    player->setIsIncanting(false);
                    if (incantationResult == "ok")
                        player->setPlayerLevel(player->getLevel() + 1);
                    break;
                }
            }
        }
    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid arguments for PIC command");
    }
}
