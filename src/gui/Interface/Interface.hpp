/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include "bar.hpp"
#include "../ServerInfo/GuiConnect.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/Tile.hpp"
#include "InventoryDisplay.hpp"
#include "InterfaceError.hpp"
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
            void command_handler();
            std::array<int, 2> get_mape_size() { return _mape_size; }
            void set_mape_size(std::array<int, 2> mape_size) { _mape_size = mape_size; }
            void set_map();
            void check_event();
            void print_resssource();
            void print_eggs();
            void print_players();
            void print_evolution(int playerIndex);
            void print_map_iso();
            void fill_color_team();
            void print_player_team();
            void set_scale_of_player(int i);
            void playBackgroundMusic(const std::string& filename);
        protected:
            bool info_;
            std::shared_ptr<sf::RenderWindow> window;
            sf::Event event;
            std::vector<std::shared_ptr<Bar>> bars;
            int tick;
            int last_tick;
            float zoom;
            float last_zoom;
            float sound_volume;
            std::vector<sf::RectangleShape> _rect;
            std::array<int, 2> _mape_size;
            std::vector<std::vector<sf::Sprite>> map_sprites;
            std::vector<std::vector<sf::Sprite>> map_iso_sprites;
            std::vector<sf::Texture> map_textures;
            std::vector<std::vector<std::vector<sf::Sprite>>> ressource_sprite;
            std::vector<sf::Sprite> ressource_sprite_;
            std::vector<sf::Texture> ressource_texture;
            std::vector<sf::Texture> tile_texture_;
            std::vector<sf::Sprite> tile_sprite_;
            std::vector<sf::Texture> tile_iso_texture;
            std::vector<sf::Sprite> tile_iso_sprite;
            sf::Sprite sprite;
            sf::Texture texture;
            std::vector<sf::Texture> textures;
            std::vector<std::shared_ptr<Player>> players;
            std::vector<sf::Sprite> player_sprites;
            std::vector<std::array<sf::IntRect, 4>> player_orientation;
            std::vector<sf::Texture> player_textures;
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
            std::vector<sf::Text> info;
            sf::RectangleShape rect;
            bool isOverTile;
            sf::Music backgroundMusic;
            std::vector<sf::Sprite> info_sprites;
            std::shared_ptr<InventoryDisplay> _inventory;
            size_t _teamnbr;
            std::vector<sf::Color> color_list_team;
        private:
    };
}

#endif /* !INTERFACE_HPP_ */
