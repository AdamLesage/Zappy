/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PDI
*/

#ifndef PDI_HPP_
#define PDI_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class PDI : public ACommand {
        public:
            PDI();
            ~PDI();

            std::vector<std::string> receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !PDI_HPP_ */
