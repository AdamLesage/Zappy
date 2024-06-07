/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDI
*/

#ifndef PDI_HPP_
#define PDI_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PDI : public ACommand {
        public:
            PDI();
            ~PDI();

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

#endif /* !PDI_HPP_ */
