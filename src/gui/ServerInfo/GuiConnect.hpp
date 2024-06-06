/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui_connect
*/

#include <iostream>
#include <array>

#ifndef GUI_CONNECT_HPP_
#define GUI_CONNECT_HPP_

#include "../ServerInfo/CommandFactory.hpp"
#include "../Entity/Inventory.hpp"

class GuiConnect {
    public:
        GuiConnect();
        GuiConnect(std::string port, std::string machine);
        ~GuiConnect() = default;
        void send(std::string message);
        void receive();
        void close_socket();
        void close_thread();
        std::array<int, 2> get_size_map() { return _size_map; } // get size map
        void set_size_map(std::array<int, 2> size_map) { _size_map = size_map; } // set size map
        std::vector<Zappy::Inventory> get_inventories() { return _inventories; } // get inventories
        Zappy::Inventory fill_inventory(std::vector<std::string> args); // fill inventories of all tiles
        void executeCommandChanges(std::string commandName, std::string message); // execute command changes from response given by factory
        

    protected:
        int _socket;
        std::array<int, 2> _size_map;
        std::vector<Zappy::Inventory> _inventories;
        int _port;
        bool Running = true;
        std::shared_ptr<Zappy::CommandFactory> _commandFactory;
    private:
};

#endif /* !GUI_CONNECT_HPP_ */
