/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include "Player.hpp"
#include "Inventory.hpp"
#include <vector>
#include <memory>

class Tile {
    public:
        Tile();
        ~Tile();

    protected:
        std::vector<Player> _players;
        std::shared_ptr<Inventory> _inventory;
    private:
};

#endif /* !TILE_HPP_ */
