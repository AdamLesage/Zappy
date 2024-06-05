/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PPO
*/

#ifndef PPO_HPP_
#define PPO_HPP_

#include "ICommand.hpp"

namespace Zappy {
    class PPO : public ICommand {
        public:
            PPO();
            ~PPO();

            void execute(std::string message) override;
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PPO_HPP_ */
