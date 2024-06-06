/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** BCT
*/

#ifndef BCT_HPP_
#define BCT_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class BCT : public ACommand {
        public:
            BCT();
            ~BCT();

            void askCommand(int socket, std::vector<std::string> args);

        protected:
        private:
    };
}

#endif /* !BCT_HPP_ */
