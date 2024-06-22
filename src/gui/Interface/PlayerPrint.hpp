/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PlayerPrint
*/
#include "Broadcast.hpp"
#include "../Entity/Evolution.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../ServerInfo/GuiConnect.hpp"
#include <memory>
#include "InterfaceError.hpp"

#ifndef PLAYERPRINT_HPP_
#define PLAYERPRINT_HPP_

namespace Zappy
{

    class PlayerPrint
    {
    public:
        PlayerPrint(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window,
        sf::Font font, int teamnbr, std::shared_ptr<Broadcast> broadcast,
        std::vector<std::pair<int, std::shared_ptr<Evolution>>> );
        ~PlayerPrint();
        void display();
        void print_walk_animation(int playerIndex);
        void set_scale_of_player(int i);
        void updatePlayersTravelled();
        std::vector<sf::Sprite> getPlayerSprites(){
            return player_sprites;
        }
        std::vector<sf::Sprite> getPlayerRank(){
            return player_rank;
        }
        std::vector<sf::Text> getPlayerRankText(){
            return player_rank_text;
        }
        std::vector<sf::Color> getColorListTeam(){
            return color_list_team;
        }
        std::vector<sf::Texture> getPlayerTextures(){
            return player_textures;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerOrientation(){
            return player_orientation;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank1(){
            return player_anim_rank1;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank2(){
            return player_anim_rank2;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank3(){
            return player_anim_rank3;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank4(){
            return player_anim_rank4;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank5(){
            return player_anim_rank5;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank6(){
            return player_anim_rank6;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank7(){
            return player_anim_rank7;
        }
        std::vector<std::array<sf::IntRect, 4>> getPlayerAnimRank8(){
            return player_anim_rank8;
        }
        std::vector<std::pair<int, std::shared_ptr<Evolution>>> getEvolutions(){
            return _evolutions;
        }
        void setEvolutions(std::vector<std::pair<int, std::shared_ptr<Evolution>>> evolutions){
            _evolutions = evolutions;
        }

    protected:
        void printPlayerEvolution(bool, int i);
        bool setPlayerEvolution(int i);
        std::vector<sf::Sprite> player_rank;
        std::vector<sf::Text> player_rank_text;
        std::shared_ptr<GuiConnect> _guiConnect;
        std::shared_ptr<sf::RenderWindow> _window;
        std::vector<sf::Sprite> player_sprites;
        sf::Font _font;
        std::vector<std::array<sf::IntRect, 4>> player_orientation;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank1;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank2;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank3;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank4;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank5;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank6;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank7;
        std::vector<std::array<sf::IntRect, 4>> player_anim_rank8;
        std::vector<sf::Texture> player_textures;
        size_t _teamnbr;
        std::vector<sf::Color> color_list_team;
        std::shared_ptr<Broadcast> _broadcast;
        std::vector<std::pair<int, std::shared_ptr<Evolution>>> _evolutions;
        std::vector<int> curr_frames;
        std::vector<float> frame_durations;
        std::vector<sf::Clock> anim_clock;
        std::vector<sf::Vector2f> start_pos;
        std::vector<sf::Vector2f> end_pos;

    private:
    };
}

#endif /* !PLAYERPRINT_HPP_ */