/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MSZ
*/

#ifndef MSZ_HPP_
#define MSZ_HPP_

#include "../ACommand.hpp"
#include <vector>

namespace Zappy {
    class MSZ : public ACommand {
        public:
            MSZ();
            ~MSZ();

            std::vector<std::string> receiveData(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !MSZ_HPP_ */
