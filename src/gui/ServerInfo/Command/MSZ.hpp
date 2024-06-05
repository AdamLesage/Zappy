/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MSZ
*/

#ifndef MSZ_HPP_
#define MSZ_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class MSZ : public ACommand {
        public:
            MSZ();
            ~MSZ();

            template<typename T>
            T execute(std::string message);
            void askCommand(int socket, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !MSZ_HPP_ */
