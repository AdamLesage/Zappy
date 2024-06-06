/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TNA
*/

#include "TNA.hpp"

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
    std::vector<std::string> args = my_str_to_line_array((char *)message.c_str()); // vector of strings like : { "tna N\n", "team1\n", "team2\n", ... }
    std::vector<std::string> teams;

    for (std::size_t i = 1; i < args.size(); i++) {
        teams.push_back(args[i].substr(4, args[i].size() - 4)); // vector of strings like : { "team1\n", "team2\n", ... }
    }
    // return format std::vector<std::string> { "tna", "team1", "team2", ... };
    return teams;
}

void Zappy::TNA::askCommand(int fd, std::vector<std::string> args)
{
    if (args.size() != 1)
        throw std::invalid_argument("Invalid number of arguments for TNA command");
    std::string message = "tna\n";
    write(fd, message.c_str(), message.size());
}
