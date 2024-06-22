/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include "PlayerPrint.hpp"
#include "bar.hpp"
#include "../Entity/Evolution.hpp"
#include "../ServerInfo/GuiConnect.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/Tile.hpp"
#include "InventoryDisplay.hpp"
#include "InfoDisplay.hpp"
#include "Broadcast.hpp"
#include "TeamPrint.hpp"
#include "InterfaceError.hpp"
#include "Menu.hpp"
#include <iostream>
#include <thread>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

namespace Zappy {
    class Interface {
        public:
            Interface();
            ~Interface();
            void loop(std::shared_ptr<GuiConnect> gui_connect);
            void print_sound();
            std::array<int, 2> get_mape_size() { return _mape_size; }
            void set_mape_size(std::array<int, 2> mape_size) { _mape_size = mape_size; }
            void set_map();
            void check_event();
            void print_resssource();
            void print_eggs();
            void playBackgroundMusic(const std::string& filename);
            void loadResources();
            void loadTiles();
            void loadTexts();
            void loadSound();
            void loadInerfaceTexture();
        protected:
            std::shared_ptr<sf::RenderWindow> window;
            sf::Event event;
            std::vector<std::shared_ptr<Bar>> bars;
            int tick;
            sf::Text tick_text;
            int last_tick;
            float zoom;
            float last_zoom;
            float sound_volume;
            std::vector<sf::RectangleShape> _rect;
            std::array<int, 2> _mape_size;
            std::vector<std::vector<sf::Sprite>> map_sprites;
            std::vector<sf::Texture> map_textures;
            std::vector<std::vector<std::vector<sf::Sprite>>> ressource_sprite;
            std::vector<sf::Sprite> ressource_sprite_;
            std::vector<sf::Texture> ressource_texture;
            std::vector<sf::Texture> tile_texture_;
            std::vector<sf::Sprite> tile_sprite_;
            sf::Sprite sprite;
            sf::Texture texture;
            std::vector<sf::Texture> textures;
            std::vector<std::shared_ptr<Player>> players;
            std::vector<sf::Sprite> egg_sprites;
            sf::Texture egg_texture;
            sf::Font font;
            std::vector<sf::Text> Texts;
            sf::Sprite sound;
            sf::Texture sound_;
            std::shared_ptr<GuiConnect> _gui_connect;
            std::thread ReceiveProcess;
            sf::View view;
            sf::Vector2i lastMousePos;
            bool isPanning;
            sf::RectangleShape rect;
            sf::RectangleShape rect2;
            bool isOverTile;
            bool isOverTile2;
            bool TileClicked;
            bool TileClicked2;
            sf::Music backgroundMusic;
            std::shared_ptr<InventoryDisplay> _inventory;
            sf::Texture interface_texture;
            std::shared_ptr<InfoDisplay> _info;
            std::shared_ptr<Broadcast> _broadcast;
            size_t _teamnbr;
            sf::Clock clock;
            std::vector<std::pair<int, std::shared_ptr<Evolution>>> evolutions;
            std::shared_ptr<TeamPrint> _teamPrint;
            std::shared_ptr<PlayerPrint> _playerPrint;
            std::shared_ptr<Menu> _menu;
        private:
    };
}

#endif /* !INTERFACE_HPP_ */
