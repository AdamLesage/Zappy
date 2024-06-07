/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandError
*/

#ifndef COMMANDERROR_HPP_
#define COMMANDERROR_HPP_

#include "../../AError.hpp"

namespace Zappy {
    class CommandError : public AError {
    public:
        CommandError(const std::string &message, const std::string &location) : AError(message, location) {}
        ~CommandError() noexcept {}
    protected:
    };
}

#endif /* !COMMANDERROR_HPP_ */