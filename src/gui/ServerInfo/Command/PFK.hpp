/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PFK_HPP_
#define PFK_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PFK : public ACommand {
        public:
            PFK();
            ~PFK();

            void applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs
            );
        protected:
        private:
    };
}

#endif /* !PFK_HPP_ */
