/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PPO
*/

#ifndef PPO_HPP_
#define PPO_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PPO : public ACommand {
        public:
            PPO();
            ~PPO();

            void askCommand(int socket, std::vector<std::string> args) override;

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

#endif /* !PPO_HPP_ */
