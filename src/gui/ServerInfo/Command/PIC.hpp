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

            std::vector<std::string> receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PIC_HPP_ */
