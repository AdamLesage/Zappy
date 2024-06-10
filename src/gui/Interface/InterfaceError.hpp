/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** InterfaceError
*/

#ifndef SCENEERROR_HPP_
#define SCENEERROR_HPP_

#include "../AError.hpp"

namespace Zappy {
    class InterfaceError : public AError {
    public:
        InterfaceError(const std::string &message, const std::string &location) : AError(message, location) {}
        ~InterfaceError() noexcept {}
    protected:
    };
}

#endif /* !SCENEERROR_HPP_ */