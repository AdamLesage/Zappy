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
#include "../Entity/Player.hpp"
#include "../Entity/Egg.hpp"

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
        std::vector<std::string> get_team_names() { return team_names; }
        std::vector<std::string> team_names;
        void executeCommandChanges(std::string commandName, std::string message); // execute command changes from response given by factory

        // DATA MANAGEMENT

        // Player management
        void createPlayer(std::vector<std::string> args);
        void deletePlayer(std::vector<std::string> args);
        void updatePlayerCoords(std::vector<std::string> args);
        void getPlayerCoords(std::vector<std::string> args);
        void getPlayerTeam(std::vector<std::string> args);
        void updatePlayerTeam(std::vector<std::string> args);
        void getPlayerInventory(std::vector<std::string> args);
        void updatePlayerInventory(std::vector<std::string> args);
        void createPlayerInventory(std::vector<std::string> args);
        void updatePlayerLevel(std::vector<std::string> args);
        void getPlayerLevel(std::vector<std::string> args);
        std::shared_ptr<Zappy::Player> getPlayerByNb(int playerNb);

        // Egg management
        void createEgg(std::vector<std::string> args);
        void deleteEgg(std::vector<std::string> args);
        void updateEgg(std::vector<std::string> args);
        std::shared_ptr<Zappy::Egg> getEggByNb(int eggNb);

        // Tile management
        void fill_inventory(std::vector<std::string> args,std::vector<Zappy::Inventory>); // fill inventories of all tiles
        void updateTileInventory(std::vector<std::string> args); // update inventory of a tile
        void createTileInvetory(std::vector<std::string> args); // create inventory of a tile
        void removeTileInventory(std::vector<std::string> args); // remove inventory of a tile

    protected:
        int _socket;
        int _port;
        bool Running = true;
        std::array<int, 2> _size_map;
        std::vector<Zappy::Inventory> _inventories;
        std::shared_ptr<Zappy::CommandFactory> _commandFactory;
        std::vector<std::shared_ptr<Zappy::Player>> _players;
        std::vector<std::shared_ptr<Zappy::Egg>> _eggs;
    private:
};

#endif /* !GUI_CONNECT_HPP_ */
