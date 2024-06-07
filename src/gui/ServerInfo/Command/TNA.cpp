/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TNA
*/

#include "TNA.hpp"
#include <algorithm>

Zappy::TNA::TNA()
{
}

Zappy::TNA::~TNA()
{
}

std::vector<std::string> Zappy::TNA::receiveData(std::string message, std::string commandName)
{
    if (strncmp(message.c_str(), commandName.c_str(), commandName.size()))
        return {};
    // receive : tna N\n * nbr_teams
    std::vector<std::string> args = my_str_to_word_array((char *)message.c_str()); // vector of strings like : { "tna N\n", "team1\n", "team2\n", ... }
    std::vector<std::string> teams;

    for (std::size_t i = 0; i < args.size(); i++) {
        teams.push_back(args[i]); // vector of strings like : { "team1\n", "team2\n", ... }
    }
    // return format std::vector<std::string> { "tna", "team1", "team2", ... };
    return teams;
}

void Zappy::TNA::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw Zappy::CommandError("Invalid number of arguments for TNA command", "TNA");
    std::string message = "tna\n";
    write(fd, message.c_str(), message.size());
}

void Zappy::TNA::applyChanges(std::vector<std::string> parsedData,
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
    // parsedData vector { "tna", team1, team2, ... }
    if (parsedData.size() < 2)
        throw Zappy::CommandError("Invalid number of arguments for TNA command", "TNA");

    try {
        for (std::size_t i = 1; i < parsedData.size(); i++) {
            if (std::find(teams.begin(), teams.end(), parsedData[i]) == teams.end()) {
                teams.push_back(parsedData[i]);
            }
        }
    } catch (std::exception &e) {
        throw Zappy::CommandError("Invalid arguments for TNA command", "TNA");
    }
}
