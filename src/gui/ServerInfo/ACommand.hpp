/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ACommand
*/

#ifndef ACOMMAND_HPP_
#define ACOMMAND_HPP_

#include "ICommand.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/Egg.hpp"
#include "../Entity/Tile.hpp"
#include "./Command/CommandError.hpp"

namespace Zappy {
    class ACommand : public ICommand {
        public:
            ACommand();
            ~ACommand();

            std::vector<std::string> receiveData(std::string message, std::string commandName);
            void askCommand(int socket, std::vector<std::string> args);
            void applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int timeUnit,
                                bool isRunning
            );
        protected:
        private:
    };
}

#endif /* !ACOMMAND_HPP_ */
