/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IPlayer
*/

#ifndef IPLAYER_HPP_
#define IPLAYER_HPP_

#include <array>
#include <iostream>
#include <memory>

namespace Zappy {
    class Inventory;
    class IPlayer {
        public:
            virtual ~IPlayer() = default;
            virtual std::string getTeamName() = 0;
            virtual std::string getPlayerName() = 0;
            virtual int getLevel() = 0;
            virtual std::array<int, 2> getPosition() = 0;
            virtual void setPosition(int x, int y) = 0;
            virtual void setPlayerNumber(int playerNumber) = 0;
            virtual int getPlayerNumber() = 0;
            virtual void setOrientation(std::string orientation) = 0;
            virtual void setTeamName(std::string teamName) = 0;
            virtual void setPlayerLevel(int level) = 0;
            virtual void setInventory(std::shared_ptr<Inventory> inventory) = 0;
            virtual std::shared_ptr<Inventory> getInventory() = 0;
            virtual bool isPlayerIncanting() = 0;
            virtual void setIsIncanting(bool isIncanting) = 0;
        protected:
        private:
    };
}

#endif /* !IPLAYER_HPP_ */
