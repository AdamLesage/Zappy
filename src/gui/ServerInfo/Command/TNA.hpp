/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TNA
*/

#ifndef TNA_HPP_
#define TNA_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class TNA {
        public:
            TNA();
            ~TNA();

            template<typename T>
            T receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args);
        protected:
        private:
    };
}

#endif /* !TNA_HPP_ */
