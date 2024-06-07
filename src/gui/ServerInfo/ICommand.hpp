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
#include <array>
#include <memory>

std::vector<std::string> my_str_to_word_array(const char *str);
std::vector<std::string> my_str_to_line_array(char *str);

namespace Zappy {
    class Inventory;
    class Player;
    class Egg;
    class Tile;

    class ICommand {
        public:
            virtual ~ICommand() = default;

            virtual void askCommand(int socket, std::vector<std::string> args) = 0;
            virtual std::vector<std::string> receiveData(std::string message, std::string commandName) = 0;
            virtual void applyChanges(std::vector<std::string> parsedData,
                                    std::array<int, 2> &size_map,
                                    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                    std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                    std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                    int timeUnit,
                                bool isRunning
            ) = 0;
        protected:
        private:
    };
}

#endif /* !ICOMMAND_HPP_ */
