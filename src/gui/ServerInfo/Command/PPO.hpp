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

            template<typename T>
            T receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PPO_HPP_ */
