/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** APlayer
*/

#ifndef APLAYER_HPP_
#define APLAYER_HPP_

#include "IPlayer.hpp"
#include "Inventory.hpp"

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
            void setPlayerNumber(int playerNumber) {_playerNumber = playerNumber;}
            int getPlayerNumber() {return _playerNumber;}
            void setOrientation(std::string orientation) {orientation = orientation;}
            void setTeamName(std::string teamName) {_teamName = teamName;}
            void setPlayerLevel(int level) {_level = level;}
            void setInventory(std::shared_ptr<Inventory> inventory) {_inventory = inventory;}
            std::shared_ptr<Inventory> getInventory() {return _inventory;}
            bool isPlayerIncanting() {return _isIncanting;}
            void setIsIncanting(bool isIncanting) {_isIncanting = isIncanting;}
            int getOrientation() {return _orientation;}
            void setOrientation(int orientation) {_orientation = orientation;}

            std::shared_ptr<Inventory> _inventory;
        protected:
            std::string _teamName;
            std::string _playerName;
            int _level;
            std::array<int, 2> _position;
            int _playerNumber;
            //std::shared_ptr<Inventory> _inventory;
            bool _isIncanting;
            int _orientation;
        private:
    };
}

#endif /* !APLAYER_HPP_ */
