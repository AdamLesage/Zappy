/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** EDI
*/

#ifndef EDI_HPP_
#define EDI_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class EDI : public ACommand {
        public:
            EDI();
            ~EDI();

            void applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::shared_ptr<Zappy::Tile>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                int timeUnit,
                                bool isRunning
            );
        protected:
        private:
    };
}

#endif /* !EDI_HPP_ */
