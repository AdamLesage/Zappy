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
#include "../Entity/Tile.hpp"

typedef struct client_managment_s {
    fd_set rfds;
    fd_set temp_fds;
    int max_fd;
    struct timeval tv;
} client_management_t;

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
        void executeCommandChanges(std::string commandName, std::string message); // execute command changes from response given by factory
        std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> getTiles() { return _tiles; } // get tiles

        // DATA MANAGEMENT

        // Player management
        void createPlayer(std::vector<std::string> args);
        void deletePlayer(int playerNb);
        void updatePlayerCoords(std::pair<int, int> coords, int playerNb);
        std::pair<int, int> getPlayerCoords(int playerNb);
        std::string getPlayerTeam(int playerNb);
        std::vector<std::string> getTeamNames() { return _teams; }
        void updatePlayerTeam(int playerNb, std::string teamName);
        std::shared_ptr<Zappy::Inventory> getPlayerInventory(int playerNb);
        void updatePlayerInventory(int playerNb, std::shared_ptr<Zappy::Inventory> inventory);
        void updatePlayerLevel(int playerNb, int level);
        int getPlayerLevel(int playerNb);
        std::shared_ptr<Zappy::Player> getPlayerByNb(int playerNb);
        std::vector<std::shared_ptr<Zappy::Player>> findPlayersByCoords(std::pair<int, int> coords);
        sf::Vector2f getVectorBetweenTwoPlayers(int playerNb1, int playerNb2);

        // Egg management
        void createEgg(std::vector<std::string> args);
        void deleteEgg(std::vector<std::string> args);
        void updateEgg(std::vector<std::string> args);
        std::shared_ptr<Zappy::Egg> getEggByNb(int eggNb);

        // Tile management
        std::vector<Zappy::Inventory> get_inventories() { return _inventories; } // get inventories
        Zappy::Inventory update_inventory(std::vector<std::string> args, Zappy::Inventory tmp); // update inventory of a tile
        std::shared_ptr<Zappy::Tile> getTileByCoords(std::pair<int, int> coords); // get tile by coords
        int getEggNbOnTile(std::pair<int, int> coords); // get egg on tile
        int getPlayerNbOnTile(std::pair<int, int> coords); // get player on tile

        void setTimeUnit(std::string args);
        int getTimeUnit() { return _timeUnit; }
        std::array<int, 2> _size_map;
        std::vector<Zappy::Inventory> _inventories;
        std::shared_ptr<Zappy::CommandFactory> _commandFactory;
        std::vector<std::shared_ptr<Zappy::Player>> _players;
        std::vector<std::shared_ptr<Zappy::Egg>> _eggs;
        std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> _tiles;
        int _timeUnit;
        bool Running = true;
    protected:
        int _socket;
        int _port;
        std::vector<std::string> _teams;
        client_management_t client_management;
    private:
        void readServer(std::string &buffer2, char *buffer);
};

#endif /* !GUI_CONNECT_HPP_ */