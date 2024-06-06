/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tile_management
*/

#include "../ServerInfo/GuiConnect.hpp"

int verifyIfNumber(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] > '9' || str[i] < '0' || str[i] != '-' || str[i] != '.')
            return 0;
    }
    return 1;
}

void GuiConnect::errorhandlingInvetory(std::vector<std::string> args)
{
    if (args.size() != 10)
        return;
    for (int i = 1; i < 10; i++)
    {
        if (verifyIfNumber(args[i]) == 0)
        {
            std::cout << "Error: Inventory is not a number" << std::endl;
            return;
        }
    }
}

std::vector<Zappy::Inventory> GuiConnect::fill_inventory(std::vector<std::string> args, std::vector<Zappy::Inventory> inventories)
{
    std::cout << "FILL INVENTORY" << std::endl;
    for (const auto &arg : args)
    {
        std::cout << arg << std::endl;
    }
    // errorhandlingInvetory(args);
    Zappy::Inventory tmp;
    update_inventory(args, tmp);
    if (inventories.size() == 0)
    {
        inventories.push_back(tmp);
        return inventories;
    }
    for (std::size_t i = 0; i < inventories.size(); i++)
    {
        if (tmp._x == inventories[i]._x && tmp._y == inventories[i]._y)
        {
            inventories[i] = tmp;
            return inventories;
        }
        else if (i == inventories.size() - 1)
        {
            inventories.push_back(tmp);
            return inventories;
        }
    }
    return inventories;
}

Zappy::Inventory GuiConnect::update_inventory(std::vector<std::string> args, Zappy::Inventory tmp)
{
    tmp.set("Food", std::stoi(args[3]));
    tmp.set("Linemate", std::stoi(args[4]));
    tmp.set("Deraumere", std::stoi(args[5]));
    tmp.set("Sibur", std::stoi(args[6]));
    tmp.set("Mendiane", std::stoi(args[7]));
    tmp.set("Phiras", std::stoi(args[8]));
    tmp.set("Thystame", std::stoi(args[9]));
    return tmp;
}