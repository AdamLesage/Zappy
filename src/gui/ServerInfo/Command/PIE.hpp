/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PEX
*/

#ifndef PIE_HPP_
#define PIE_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PIE : public ACommand {
        public:
            PIE();
            ~PIE();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PIE_HPP_ */
