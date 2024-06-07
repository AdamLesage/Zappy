/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tile_management
*/

#include "../ServerInfo/GuiConnect.hpp"

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