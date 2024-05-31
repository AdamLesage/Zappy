/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AError
*/

#ifndef AERROR_HPP_
#define AERROR_HPP_

#include "IError.hpp"
#include <iostream>

namespace Zappy {
    class AError : public IError {
        public:
            AError(const std::string& message, const std::string& location) {
                _errorMessage = message;
                _errorLocation = location;
            }
            virtual ~AError() noexcept = default;
            const char* what() const noexcept override {return (_errorMessage.c_str());}
            const char* where() const noexcept {return (_errorLocation.c_str());}

        protected:
            std::string _errorMessage;
            std::string _errorLocation;
    };
}

#endif /* !AERROR_HPP_ */
