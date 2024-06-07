/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIN
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PIN : public ACommand {
        public:
            PIN();
            ~PIN();

            void askCommand(int socket, std::vector<std::string> args) override;

            void applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int timeUnit,
                                bool isRunning
            ) override;
        protected:
        private:
    };
}

#endif /* !PIN_HPP_ */
