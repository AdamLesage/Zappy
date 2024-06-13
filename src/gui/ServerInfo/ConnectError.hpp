/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ConnectError
*/

#ifndef CONNECT_ERROR_HPP_
#define CONNECT_ERROR_HPP_

#include "../AError.hpp"

namespace Zappy {
    class ConnectError : public AError {
    public:
        ConnectError(const std::string &message, const std::string &location) : AError(message, location) {}
        ~ConnectError() noexcept {}
    protected:
    };
}

#endif /* !CONNECT_ERROR_HPP_ */