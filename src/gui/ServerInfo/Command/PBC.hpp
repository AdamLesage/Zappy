/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PBC_HPP_
#define PBC_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PBC : public ACommand {
        public:
            PBC();
            ~PBC();

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

#endif /* !PBC_HPP_ */
