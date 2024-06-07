/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SGT
*/

#ifndef SGT_HPP_
#define SGT_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class SGT : public ACommand {
        public:
            SGT();
            ~SGT();

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

#endif /* !SGT_HPP_ */
