/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AInventory
*/

#include "IInventory.hpp"

#ifndef AINVENTORY_HPP_
#define AINVENTORY_HPP_

namespace Zappy {
    class AInventory : public IInventory
    {
        public:
            ~AInventory() = default;
            int get(std::string name);
            void set(std::string name, int value);
            void setpos(int x, int y);
            void add(std::string name, int value);
            void remove(std::string name, int value);
            void Empty_all();
            int _food;
            int _linemate;
            int _deraumere;
            int _sibur;
            int _mendiane;
            int _phiras;
            int _thystame;
            int _x;
            int _y;
        private:
    };
}

#endif /* !AINVENTORY_HPP_ */
