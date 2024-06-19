/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PEX_HPP_
#define PEX_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PEX : public ACommand {
        public:
            PEX();
            ~PEX();


        void applyChanges(std::vector<std::string> parsedData,
                                std::array<int, 2> &size_map,
                                std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> &tiles,
                                std::vector<std::shared_ptr<Zappy::Player>> &players, 
                                std::vector<std::shared_ptr<Zappy::Egg>> &eggs,
                                std::vector<std::string> &teams,
                                int &timeUnit,
                                bool &isRunning
            ) override;
        protected:
        private:
    };
}

#endif /* !PEX_HPP_ */
