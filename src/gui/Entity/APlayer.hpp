/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** APlayer
*/

#include "IPlayer.hpp"

#ifndef APLAYER_HPP_
#define APLAYER_HPP_

namespace Zappy {
    class APlayer : public IPlayer
    {
        public:
            ~APlayer() = default;
            std::string getTeamName(){return _teamName;}
            std::string getPlayerName(){return _playerName;}
            int getLevel(){return _level;}
            std::array<int, 2> getPosition(){return _position;}
            void setPosition(int x, int y) {_position[0] = x; _position[1] = y;}
        protected:
            std::string _teamName;
            std::string _playerName;
            int _level;
            std::array<int, 2> _position;
            int _playerNumber;
        private:
    };
}

#endif /* !APLAYER_HPP_ */
