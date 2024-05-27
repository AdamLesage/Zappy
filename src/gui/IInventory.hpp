/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IInventory
*/

#include <iostream>

#ifndef IINVENTORY_HPP_
#define IINVENTORY_HPP_

class IInventory {
    public:
        ~IInventory() = default;
        virtual int get(std::string name) = 0;
        virtual void set(std::string name, int value) = 0;
        virtual void add(std::string name, int value) = 0;
        virtual void remove(std::string name, int value) = 0;
        virtual void Empty_all() = 0;

    protected:
    private:
};

#endif /* !IINVENTORY_HPP_ */
