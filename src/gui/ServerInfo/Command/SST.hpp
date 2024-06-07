/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SST
*/

#ifndef SST_HPP_
#define SST_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class SST : public ACommand {
        public:
            SST();
            ~SST();

            void askCommand(int socket, std::vector<std::string> args);
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

#endif /* !SST_HPP_ */
