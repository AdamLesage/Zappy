/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MCT
*/

#ifndef MCT_HPP_
#define MCT_HPP_

#include "../ACommand.hpp"

namespace Zappy {
    class MCT : public ACommand {
        public:
            MCT();
            ~MCT();

            void askCommand(int fd, std::vector<std::string> args) override;
        protected:
        private:
    };
}

#endif /* !MCT_HPP_ */
