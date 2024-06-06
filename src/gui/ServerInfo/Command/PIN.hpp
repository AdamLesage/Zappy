/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIN
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PIN : public ACommand {
        public:
            PIN();
            ~PIN();

            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PIN_HPP_ */
