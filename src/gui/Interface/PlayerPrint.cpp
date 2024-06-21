/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PlayerPrint
*/

#include "PlayerPrint.hpp"


Zappy::PlayerPrint::PlayerPrint(std::shared_ptr<GuiConnect> guiConnect, std::shared_ptr<sf::RenderWindow> window,sf::Font font,
int teamnbr, std::shared_ptr<Broadcast> brodcasr, std::vector<std::pair<int, std::shared_ptr<Evolution>>> evolu)
{
    this->_window = window;
    this->_guiConnect = guiConnect;
    this->_font = font;
    this->_teamnbr = teamnbr;
    this->_broadcast = brodcasr;
    this->_evolutions = evolu;
    for (int i = 0; i < 8; i++)
        player_textures.push_back(sf::Texture());
    if (player_textures[0].loadFromFile("./asset/sprite/rank/rank1.png") == false)
        throw InterfaceError("Error: rank1.png not found", "Interface");
    if (player_textures[1].loadFromFile("./asset/sprite/rank/rank2.png") == false)
        throw InterfaceError("Error: rank2.png not found", "Interface");
    if (player_textures[2].loadFromFile("./asset/sprite/rank/rank3.png") == false)
        throw InterfaceError("Error: rank3.png not found", "Interface");
    if (player_textures[3].loadFromFile("./asset/sprite/rank/rank4.png") == false)
        throw InterfaceError("Error: rank4.png not found", "Interface");
    if (player_textures[4].loadFromFile("./asset/sprite/rank/rank5.png") == false)
        throw InterfaceError("Error: rank5.png not found", "Interface");
    if (player_textures[5].loadFromFile("./asset/sprite/rank/rank6.png") == false)
        throw InterfaceError("Error: rank6.png not found", "Interface");
    if (player_textures[6].loadFromFile("./asset/sprite/rank/rank7.png") == false)
        throw InterfaceError("Error: rank7.png not found", "Interface");
    if (player_textures[7].loadFromFile("./asset/sprite/rank/rank8.png") == false)
        throw InterfaceError("Error: rank8.png not found", "Interface");
    for (int i = 0; i < 8; i++) {
        player_rank.push_back(sf::Sprite());
        player_rank_text.push_back(sf::Text("Level " + std::to_string(i), font, 40));
        player_rank[i].setTexture(player_textures[i]);
        player_rank_text[i].setFillColor(sf::Color::White);
        player_rank[i].setPosition(10, 100 + i * 100);
        player_rank_text[i].setPosition(100, 100 + i * 100);
    }
    player_rank[0].setScale(1.5, 1.5);
    player_rank[1].setScale(1.5, 1.5);
    player_rank[2].setScale(1.5, 1.5);
    for (int i = 0; i < 8; i++) {
        player_orientation.push_back(std::array<sf::IntRect, 4>());
    }
    for (int i = 0; i < 5; i++) {
        player_anim_rank1.push_back(std::array<sf::IntRect, 4>());
        player_anim_rank2.push_back(std::array<sf::IntRect, 4>());
        player_anim_rank3.push_back(std::array<sf::IntRect, 4>());
        player_anim_rank4.push_back(std::array<sf::IntRect, 4>());
        player_anim_rank5.push_back(std::array<sf::IntRect, 4>());
        player_anim_rank6.push_back(std::array<sf::IntRect, 4>());
        player_anim_rank7.push_back(std::array<sf::IntRect, 4>());
        player_anim_rank8.push_back(std::array<sf::IntRect, 4>());
    }
    player_anim_rank1[0][0] = sf::IntRect(5, 3, 21, 29);
    player_anim_rank1[0][1] = sf::IntRect(69, 3, 21, 29);
    player_anim_rank1[0][2] = sf::IntRect(5, 3, 21, 29);
    player_anim_rank1[0][3] = sf::IntRect(69, 3, 21, 29);
    player_anim_rank1[1][0] = sf::IntRect(0, 103, 31, 24);
    player_anim_rank1[1][1] = sf::IntRect(63, 103, 32, 24);
    player_anim_rank1[1][2] = sf::IntRect(0, 103, 31, 24);
    player_anim_rank1[1][3] = sf::IntRect(63, 103, 32, 24);
    player_anim_rank1[2][0] = sf::IntRect(5, 66, 21, 30);
    player_anim_rank1[2][1] = sf::IntRect(69, 66, 21, 30);
    player_anim_rank1[2][2] = sf::IntRect(5, 66, 21, 30);
    player_anim_rank1[2][3] = sf::IntRect(69, 66, 21, 30);
    player_anim_rank1[3][0] = sf::IntRect(0, 39, 30, 25);
    player_anim_rank1[3][1] = sf::IntRect(64, 39, 30, 24);
    player_anim_rank1[3][2] = sf::IntRect(0, 39, 32, 25);
    player_anim_rank1[3][3] = sf::IntRect(64, 39, 30, 24);
    player_anim_rank2[0][0] = sf::IntRect(5, 3, 21, 29);
    player_anim_rank2[0][1] = sf::IntRect(69, 3, 21, 29);
    player_anim_rank2[0][2] = sf::IntRect(5, 3, 21, 29);
    player_anim_rank2[0][3] = sf::IntRect(69, 3, 21, 29);
    player_anim_rank2[1][0] = sf::IntRect(0, 103, 31, 24);
    player_anim_rank2[1][1] = sf::IntRect(63, 103, 32, 24);
    player_anim_rank2[1][2] = sf::IntRect(0, 103, 31, 24);
    player_anim_rank2[1][3] = sf::IntRect(63, 103, 32, 24);
    player_anim_rank2[2][0] = sf::IntRect(5, 66, 21, 30);
    player_anim_rank2[2][1] = sf::IntRect(69, 66, 21, 30);
    player_anim_rank2[2][2] = sf::IntRect(5, 66, 21, 30);
    player_anim_rank2[2][3] = sf::IntRect(69, 66, 21, 30);
    player_anim_rank2[3][0] = sf::IntRect(0, 39, 30, 25);
    player_anim_rank2[3][1] = sf::IntRect(64, 39, 30, 24);
    player_anim_rank2[3][2] = sf::IntRect(0, 39, 32, 25);
    player_anim_rank2[3][3] = sf::IntRect(64, 39, 30, 24);

    player_orientation[0][0] = sf::IntRect(35, 2, 23, 27);
    player_orientation[0][3] = sf::IntRect(32, 103, 31, 24);
    player_orientation[0][2] = sf::IntRect(37, 65, 21, 28);
    player_orientation[0][1] = sf::IntRect(33, 38, 30, 25);
    player_orientation[1][0] = sf::IntRect(35, 2, 23, 27);
    player_orientation[1][3] = sf::IntRect(32, 103, 31, 24);
    player_orientation[1][2] = sf::IntRect(37, 65, 21, 28);
    player_orientation[1][1] = sf::IntRect(33, 38, 30, 25);
    player_orientation[2][0] = sf::IntRect(182, 137, 19, 29);
    player_orientation[2][3] = sf::IntRect(207, 293, 28, 23);
    player_orientation[2][2] = sf::IntRect(178, 51, 20, 27);
    player_orientation[2][1] = sf::IntRect(178, 217, 27, 26);
    player_orientation[3][0] = sf::IntRect(53, 538, 21, 66);
    player_orientation[3][3] = sf::IntRect(35, 678, 53, 51);
    player_orientation[3][2] = sf::IntRect(53, 801, 21, 55);
    player_orientation[3][1] = sf::IntRect(39, 935, 54, 51);
    player_orientation[4][0] = sf::IntRect(437, 42, 22, 47);
    player_orientation[4][3] = sf::IntRect(417, 180, 56, 31);
    player_orientation[4][2] = sf::IntRect(437, 301, 22, 45);
    player_orientation[4][1] = sf::IntRect(422, 436, 56, 31);
    player_orientation[5][0] = sf::IntRect(432, 38, 29, 49);
    player_orientation[5][3] = sf::IntRect(420, 170, 50, 30);
    player_orientation[5][2] = sf::IntRect(433, 302, 30, 41);
    player_orientation[5][1] = sf::IntRect(425, 426, 50, 40);
    player_orientation[6][0] = sf::IntRect(434, 39, 28, 71);
    player_orientation[6][3] = sf::IntRect(403, 171, 71, 44);
    player_orientation[6][2] = sf::IntRect(434, 300, 28, 58);
    player_orientation[6][1] = sf::IntRect(419, 427, 72, 44);
    player_orientation[7][0] = sf::IntRect(83, 20, 25, 64);
    player_orientation[7][3] = sf::IntRect(64, 278, 64, 61);
    player_orientation[7][2] = sf::IntRect(84, 202, 22, 51);
    player_orientation[7][1] = sf::IntRect(63, 108, 64, 62);
    for (int i = 0; i < 8; i++) {
        player_rank[i].setTextureRect(player_orientation[i][3]);
    }
}

Zappy::PlayerPrint::~PlayerPrint()
{
}

void Zappy::PlayerPrint::set_scale_of_player(int i)
{
    if (this->_guiConnect->_players[i]->getLevel() == 1)
        player_sprites[i].setScale(1, 1);
    else if (this->_guiConnect->_players[i]->getLevel() == 2)
        player_sprites[i].setScale(1, 1);
    else if (this->_guiConnect->_players[i]->getLevel() == 4)
        player_sprites[i].setScale(0.5, 0.5);
    else if (this->_guiConnect->_players[i]->getLevel() == 5)
        player_sprites[i].setScale(0.5, 0.5);
    else if (this->_guiConnect->_players[i]->getLevel() == 6)
        player_sprites[i].setScale(0.5, 0.5);
    else if (this->_guiConnect->_players[i]->getLevel() == 7)
        player_sprites[i].setScale(0.5, 0.5);
    else if (this->_guiConnect->_players[i]->getLevel() == 8)
        player_sprites[i].setScale(0.5, 0.5);
}


void Zappy::PlayerPrint::fill_color_team()
{
    for (size_t i = 0; i <= _teamnbr; i++ and i <= color_list_team.size() ) {
        sf::Color color;
        color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
        color_list_team.push_back(color);
    }
}


void Zappy::PlayerPrint::print_player_team()
{
    std::vector<std::string> team_list;

    for (size_t i = 0; i < this->_guiConnect->_players.size(); i++) {
        std::string team_name = this->_guiConnect->_players[i]->getTeamName();
        bool team_exists = false;
        for (const std::string& team : team_list) {
            if (team == team_name) {
                team_exists = true;
                break;
            }
        }
        if (!team_exists) {
            team_list.push_back(team_name);
        }
    }

      for (const auto& player : this->_guiConnect->_players) {
            sf::RectangleShape playerSquare(sf::Vector2f(2, 2));
            std::string team_name = player->getTeamName();
            int team_index = 0;
            for (size_t i = 0; i < team_list.size(); i++) {
                if (team_list[i] == team_name) {
                    team_index = i;
                    break;
                }
            }
            playerSquare.setFillColor(color_list_team[team_index]);
            playerSquare.setPosition(player->getPosition()[0] * 102.4 + 112, player->getPosition()[1] * 102.4 + 162);
            this->_window->draw(playerSquare);
        }
}


void Zappy::PlayerPrint::updatePlayersTravelled()
{
    for (size_t i = 0; i < this->_guiConnect->_players.size(); i++) {
        if (this->_guiConnect->_players[i]->getLastPosition() != this->_guiConnect->_players[i]->getPosition()) {
            this->_guiConnect->_players[i]->setTravelled(this->_guiConnect->_players[i]->getTravelled() + 1);
        }
    }
    for (size_t i = 0; i < this->_guiConnect->_players.size(); i++) {
        std::array<int, 2> playerPosition = this->_guiConnect->_players[i]->getPosition();
        this->_guiConnect->_players[i]->setLastPosition(playerPosition[0], playerPosition[1]);
    }
}

void Zappy::PlayerPrint::print_walk_animation(int playerIndex)
{
    playerIndex = playerIndex;
    // std::shared_ptr<Player> player = this->_guiConnect->_players[playerIndex];
    // sf::Sprite& sprite = this->player_sprites[playerIndex];
    // int level = player->getLevel() - 1;
    // float time_spent = this->anim_clock[playerIndex].getElapsedTime().asSeconds();
    // float total_duration = 0.4f;

    // if (time_spent < total_duration) {
    //     sf::Vector2f newPosition = this->start_pos[playerIndex] + 
    //         (this->end_pos[playerIndex] - this->start_pos[playerIndex]) * (time_spent / total_duration);
    //     sprite.setPosition(newPosition);

    //     int frameIndex = static_cast<int>((time_spent / total_duration) * 4) % 4;
    //     sprite.setTextureRect(this->player_orientation[level][frameIndex]);
    // } else {
    //     sprite.setPosition(this->end_pos[playerIndex]);
    //     sprite.setTextureRect(this->player_orientation[level][0]);
    // }
}

void Zappy::PlayerPrint::display()
{
    for (size_t i = 0; i < this->_guiConnect->_players.size(); i++) {
        if (player_sprites.size() < this->_guiConnect->_players.size()) {
            player_sprites.push_back(sf::Sprite());
            _evolutions.push_back(std::make_pair(0, std::make_shared<Evolution>(std::make_pair(0, 0), std::make_pair(1, 1), sf::Clock(), "asset/sprite/animation/evolution1.png")));
            _evolutions.back().second->setFrameInfo(82, 67, 16, 2);
        }
        if (this->_guiConnect->_players[i]->getLastPosition() != this->_guiConnect->_players[i]->getPosition()) {
            print_walk_animation(i);
        }
        player_sprites[i].setTexture(player_textures[this->_guiConnect->_players[i]->getLevel() - 1]);
        set_scale_of_player(i);
        player_sprites[i].setPosition(this->_guiConnect->_players[i]->getPosition()[0] * 102.4 + 100, this->_guiConnect->_players[i]->getPosition()[1] * 102.4 + 150);
        player_sprites[i].setTextureRect(player_orientation[this->_guiConnect->_players[i]->getLevel() - 1][this->_guiConnect->_players[i]->getOrientation() - 1]);
        this->_window->draw(player_sprites[i]);
        updatePlayersTravelled();
        _broadcast->check_player_broadcast(i);
        _broadcast->display(i);
        if (this->_guiConnect->_players[i].get()->isPlayerIncanting() == true) {
            _evolutions[i].second->setPosition(this->_guiConnect->_players[i]->getPosition()[0] * 102.4 + 70, this->_guiConnect->_players[i]->getPosition()[1] * 102.4 + 125);
            this->_window->draw(_evolutions[i].second->getSprite());
        }
    }
}