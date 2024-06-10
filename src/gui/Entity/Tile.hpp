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
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace Zappy {
    class Tile {
        public:
            Tile();
            Tile(sf::Vector2f position, std::shared_ptr<Inventory> inventory);
            ~Tile();
            std::shared_ptr<Inventory> _inventory;
            sf::Vector2f getPosition() const;


            std::vector<Player> _players;
            sf::Vector2f _position;
        protected:
        private:
    };
}

#endif /* !TILE_HPP_ */
