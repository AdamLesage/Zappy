/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IPlayer
*/

#include <array>
#include <iostream>

#ifndef IPLAYER_HPP_
#define IPLAYER_HPP_

namespace Zappy {
    class IPlayer {
        public:
            ~IPlayer() = default;
            virtual std::string getTeamName() = 0;
            virtual std::string getPlayerName() = 0;
            virtual int getLevel() = 0;
            virtual std::array<int, 2> getPosition() = 0;
            virtual void setPosition(int x, int y) = 0;
        protected:
        private:
    };
}

#endif /* !IPLAYER_HPP_ */
