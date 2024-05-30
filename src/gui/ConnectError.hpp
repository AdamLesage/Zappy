/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ConnectError
*/

#ifndef SCENEERROR_HPP_
#define SCENEERROR_HPP_

#include "AError.hpp"

namespace Zappy {
    class ConnectError : public AError {
    public:
        ConnectError(const std::string &message, const std::string &location) : AError(message, location) {}
        ~ConnectError() noexcept {}
    protected:
    };
}

#endif /* !SCENEERROR_HPP_ */