/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PLV
*/

#ifndef PLV_HPP_
#define PLV_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PLV : public ACommand {
        public:
            PLV();
            ~PLV();

            void askCommand(int socket, std::vector<std::string> args) override;

            void applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
            ) override;
        protected:
        private:
    };
}

#endif /* !PLV_HPP_ */
