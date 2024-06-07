/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PDR_HPP_
#define PDR_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PDR : public ACommand {
        public:
            PDR();
            ~PDR();

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

#endif /* !PDR_HPP_ */
