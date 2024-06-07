/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PIC_HPP_
#define PIC_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PIC : public ACommand {
        public:
            PIC();
            ~PIC();

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

#endif /* !PIC_HPP_ */
