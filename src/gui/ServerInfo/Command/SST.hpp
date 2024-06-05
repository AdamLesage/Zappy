/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SST
*/

#ifndef SST_HPP_
#define SST_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class SST : public ACommand {
        public:
            SST();
            ~SST();

            void askCommand(int socket, std::vector<std::string> args);
        protected:
        private:
    };
}

#endif /* !SST_HPP_ */
