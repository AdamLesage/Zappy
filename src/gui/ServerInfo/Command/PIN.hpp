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

            std::vector<std::string> receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PIN_HPP_ */
