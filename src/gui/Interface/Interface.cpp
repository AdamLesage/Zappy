/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Interface
*/

#include <unistd.h>
#include "Interface.hpp"

Zappy::Interface::Interface()
{
    sound_volume = 50;
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(1920, 1080), "Zappy");
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 125), sf::Color(150, 150, 150), 5, sf::Color::Black));
    bars.push_back(std::make_shared<Bar>(sf::Vector2f(20, 50), sf::Vector2f(200, 40), sf::Vector2f(1700, 325), sf::Color(150, 150, 150), 5, sf::Color::Black));
    if (texture.loadFromFile("./asset/sprite/tiles/tile1.png") == false)
        throw InterfaceError("Error: tile1.png not found", "Interface");
    sprite.setTexture(texture);
    sprite.setScale(0.32, 0.32);
    // sprite.setColor(sf::Color(255, 255, 255, 150));
    for (int i = 0; i < 6; i++)
        tile_texture_.push_back(sf::Texture());
    if (tile_texture_[0].loadFromFile("./asset/sprite/tiles/tile1.png") == false)
        throw InterfaceError("Error: tile1.png not found", "Interface");
    if (tile_texture_[1].loadFromFile("./asset/sprite/tiles/tile2.png") == false)
        throw InterfaceError("Error: tile2.png not found", "Interface");
    if (tile_texture_[2].loadFromFile("./asset/sprite/tiles/tile3.png") == false)
        throw InterfaceError("Error: tile3.png not found", "Interface");
    if (tile_texture_[3].loadFromFile("./asset/sprite/tiles/tile4.png") == false)
        throw InterfaceError("Error: tile4.png not found", "Interface");
    if (tile_texture_[4].loadFromFile("./asset/sprite/tiles/tile5.png") == false)
        throw InterfaceError("Error: tile5.png not found", "Interface");
    if (tile_texture_[5].loadFromFile("./asset/sprite/tiles/tile6.png") == false)
        throw InterfaceError("Error: tile6.png not found", "Interface");
    for (int i = 0; i < 6; i++) {
        tile_sprite_.push_back(sf::Sprite());
        tile_sprite_[i].setTexture(tile_texture_[i]);
        tile_sprite_[i].setScale(0.32, 0.32);
        // tile_sprite_[i].setColor(sf::Color(255, 255, 255, 200));
    }
    for (int i = 0; i < 6; i++)
        tile_iso_texture.push_back(sf::Texture());
    if (tile_iso_texture[0].loadFromFile("./asset/sprite/tiles/tile1w.png") == false)
        throw InterfaceError("Error: tile1w.png not found", "Interface");
    if (tile_iso_texture[1].loadFromFile("./asset/sprite/tiles/tile2w.png") == false)
        throw InterfaceError("Error: tile2w.png not found", "Interface");
    if (tile_iso_texture[2].loadFromFile("./asset/sprite/tiles/tile3w.png") == false)
        throw InterfaceError("Error: tile3w.png not found", "Interface");
    if (tile_iso_texture[3].loadFromFile("./asset/sprite/tiles/tile4w.png") == false)
        throw InterfaceError("Error: tile4w.png not found", "Interface");
    if (tile_iso_texture[4].loadFromFile("./asset/sprite/tiles/tile5w.png") == false)
        throw InterfaceError("Error: tile5w.png not found", "Interface");
    if (tile_iso_texture[5].loadFromFile("./asset/sprite/tiles/tile6w.png") == false)
        throw InterfaceError("Error: tile6w.png not found", "Interface");
    for (int i = 0; i < 6; i++) {
        tile_iso_sprite.push_back(sf::Sprite());
        tile_iso_sprite[i].setTexture(tile_iso_texture[i]);
        tile_iso_sprite[i].setScale(0.32, 0.32);
        tile_iso_sprite[i].setColor(sf::Color(255, 255, 255, 230));
    }
    font.loadFromFile("./asset/gui/Farmhouse.otf");
    if (font.loadFromFile("./asset/gui/Farmhouse.otf") == false)
        throw InterfaceError("Error: Farmhouse.otf not found", "Interface");
    Texts.push_back(sf::Text("tick", font, 50));
    Texts.push_back(sf::Text("Team: ", font, 50));
    Texts[0].setFillColor(sf::Color::Black);
    Texts[1].setFillColor(sf::Color::Black);
    Texts[0].setPosition(1750, 225);
    Texts[1].setPosition(10, 50);
    if (sound_.loadFromFile("./asset/gui/soundbar_logo.png") == false)
        throw InterfaceError("Error: soundbar_logo.png not found", "Interface");
    sound.setTexture(sound_);
    sound.setPosition(1725, 10);
    sound.setScale(0.3, 0.3);
    sound.setTextureRect(sf::IntRect(0, 0, 450, 325));

    if (interface_texture.loadFromFile("./asset/gui/grass.jpg") == false) {
        throw InterfaceError("Error: bg_texture.png not found", "Interface");
    }
    _rect.push_back(sf::RectangleShape(sf::Vector2f(230, 1080)));
    _rect[0].setFillColor(sf::Color(8, 105, 36));
    _rect.push_back(sf::RectangleShape(sf::Vector2f(1920, 75)));
    _rect[0].setTexture(&interface_texture);
    _rect[1].setFillColor(sf::Color(8, 105, 36));
    _rect.push_back(sf::RectangleShape(sf::Vector2f(230, 1080)));
    _rect[1].setTexture(&interface_texture);
    _rect[2].setFillColor(sf::Color(8, 105, 36));
    _rect[2].setPosition(1920 - 230, 0);
    _rect.push_back(sf::RectangleShape(sf::Vector2f(1920, 300)));
    _rect[2].setTexture(&interface_texture);
    _rect[3].setFillColor(sf::Color(8, 105, 36));
    _rect[3].setPosition(0, 1080 - 300);
    _rect[3].setTexture(&interface_texture);


    zoom = 100;
    last_zoom = 100;
    view.setSize(1920, 1080);
    isPanning = false;
    for (int i = 0; i < 7; i++)
        ressource_texture.push_back(sf::Texture());
    if (ressource_texture[0].loadFromFile("./asset/sprite/ressource/bacon.png") == false)
        throw InterfaceError("Error: bacon.png not found", "Interface");
    if (ressource_texture[1].loadFromFile("./asset/sprite/ressource/egg.png") == false)
        throw InterfaceError("Error: egg.png not found", "Interface");
    if (ressource_texture[2].loadFromFile("./asset/sprite/ressource/milk.png") == false)
        throw InterfaceError("Error: milk.png not found", "Interface");
    if (ressource_texture[3].loadFromFile("./asset/sprite/ressource/horseshoes.png") == false)
        throw InterfaceError("Error: horseshoes.png not found", "Interface");
    if (ressource_texture[4].loadFromFile("./asset/sprite/ressource/rabbit_hide.png") == false)
        throw InterfaceError("Error: rabbit_hide.png not found", "Interface");
    if (ressource_texture[5].loadFromFile("./asset/sprite/ressource/wool.png") == false)
        throw InterfaceError("Error: wool.png not found", "Interface");
    if (ressource_texture[6].loadFromFile("./asset/sprite/ressource/wheat.png") == false)
        throw InterfaceError("Error: wheat.png not found", "Interface");
    for (int i = 0; i < 7; i++) {
        ressource_sprite_.push_back(sf::Sprite());
    }
    ressource_sprite_[0].setTexture(ressource_texture[0]);
    ressource_sprite_[0].setScale(0.05, 0.05);
    ressource_sprite_[1].setTexture(ressource_texture[1]);
    ressource_sprite_[1].setScale(0.015, 0.015);
    ressource_sprite_[2].setTexture(ressource_texture[2]);
    ressource_sprite_[2].setScale(0.025, 0.025);
    ressource_sprite_[3].setTexture(ressource_texture[3]);
    ressource_sprite_[3].setScale(0.05, 0.05);
    ressource_sprite_[4].setTexture(ressource_texture[4]);
    ressource_sprite_[4].setScale(0.05, 0.05);
    ressource_sprite_[5].setTexture(ressource_texture[5]);
    ressource_sprite_[5].setScale(0.05, 0.05);
    ressource_sprite_[6].setTexture(ressource_texture[6]);
    ressource_sprite_[6].setScale(0.05, 0.05);
    if (egg_texture.loadFromFile("./asset/sprite/egg.png") == false)
        throw InterfaceError("Error: egg.png not found", "Interface");
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
        player_orientation.push_back(std::array<sf::IntRect, 4>());
    }
    player_orientation[0][0] = sf::IntRect(35, 0, 35, 35);
    player_orientation[0][1] = sf::IntRect(30, 100, 35, 35);
    player_orientation[0][2] = sf::IntRect(30, 65, 35, 35);
    player_orientation[0][3] = sf::IntRect(35, 35, 30, 30);
    player_orientation[1][0] = sf::IntRect(35, 0, 35, 35);
    player_orientation[1][1] = sf::IntRect(30, 100, 35, 35);
    player_orientation[1][2] = sf::IntRect(30, 65, 35, 35);
    player_orientation[1][3] = sf::IntRect(35, 35, 30, 30);
    player_orientation[2][0] = sf::IntRect(182, 137, 19, 29);
    player_orientation[2][1] = sf::IntRect(178, 217, 27, 26);
    player_orientation[2][2] = sf::IntRect(178, 51, 20, 27);
    player_orientation[2][3] = sf::IntRect(207, 293, 28, 23);
    player_orientation[3][0] = sf::IntRect(53, 801, 21, 55);
    player_orientation[3][1] = sf::IntRect(39, 935, 54, 51);
    player_orientation[3][2] = sf::IntRect(53, 538, 21, 66);
    player_orientation[3][3] = sf::IntRect(35, 678, 53, 51);
    player_orientation[4][0] = sf::IntRect(437, 42, 22, 47);
    player_orientation[4][1] = sf::IntRect(417, 180, 56, 31);
    player_orientation[4][2] = sf::IntRect(437, 301, 22, 45);
    player_orientation[4][3] = sf::IntRect(422, 436, 56, 31);
    player_orientation[5][0] = sf::IntRect(432, 38, 29, 49);
    player_orientation[5][1] = sf::IntRect(420, 170, 50, 30);
    player_orientation[5][2] = sf::IntRect(433, 302, 30, 41);
    player_orientation[5][3] = sf::IntRect(425, 426, 50, 40);
    player_orientation[6][0] = sf::IntRect(434, 39, 28, 71);
    player_orientation[6][1] = sf::IntRect(403, 171, 71, 44);
    player_orientation[6][2] = sf::IntRect(434, 300, 28, 58);
    player_orientation[6][3] = sf::IntRect(419, 427, 72, 44);
    player_orientation[7][0] = sf::IntRect(83, 20, 25, 64);
    player_orientation[7][1] = sf::IntRect(63, 108, 64, 62);
    player_orientation[7][2] = sf::IntRect(84, 202, 22, 51);
    player_orientation[7][3] = sf::IntRect(64, 278, 64, 61);

    rect = sf::RectangleShape(sf::Vector2f(102.4, 102.4));
    rect.setFillColor(sf::Color(150, 150, 150, 150));
    // broadcast_textures.push_back(sf::Texture());
    // if (broadcast_textures[0].loadFromFile("./asset/sprite/broadcast/talk_buble.png") == false)
    //     throw InterfaceError("Error: broadcast2.png not found", "Interface");
    // broadcast_textures.push_back(sf::Texture());
    // if (broadcast_textures[1].loadFromFile("./asset/sprite/broadcast/message.png") == false)
    //     throw InterfaceError("Error: broadcast.png not found", "Interface");
    // broadcast_sprites.push_back(sf::Sprite());
    // broadcast_sprites.push_back(sf::Sprite());
    // broadcast_sprites[0].setTexture(broadcast_textures[0]);
    // broadcast_send[0].setTexture(broadcast_textures[1]);

}

void Zappy::Interface::set_scale_of_player(int i)
{
    if (_gui_connect->_players[i]->getLevel() == 1)
        player_sprites[i].setScale(1, 1);
    else if (_gui_connect->_players[i]->getLevel() == 2)
        player_sprites[i].setScale(1, 1);
    else if (_gui_connect->_players[i]->getLevel() == 4)
        player_sprites[i].setScale(0.5, 0.5);
    else if (_gui_connect->_players[i]->getLevel() == 5)
        player_sprites[i].setScale(0.5, 0.5);
    else if (_gui_connect->_players[i]->getLevel() == 6)
        player_sprites[i].setScale(0.5, 0.5);
    else if (_gui_connect->_players[i]->getLevel() == 7)
        player_sprites[i].setScale(0.5, 0.5);
    else if (_gui_connect->_players[i]->getLevel() == 8)
        player_sprites[i].setScale(0.5, 0.5);
}

void Zappy::Interface::print_player_team()
{
    std::vector<std::string> team_list;

    for (int i = 0; i < _gui_connect->_players.size(); i++) {
        std::string team_name = _gui_connect->_players[i]->getTeamName();
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

      for (const auto& player : _gui_connect->_players) {
            sf::RectangleShape playerSquare(sf::Vector2f(2, 2));
            std::string team_name = player->getTeamName();
            int team_index = 0;
            for (int i = 0; i < team_list.size(); i++) {
                if (team_list[i] == team_name) {
                    team_index = i;
                    break;
                }
            }
            playerSquare.setFillColor(color_list_team[team_index]);
            playerSquare.setPosition(player->getPosition()[0] * 102.4 + 112, player->getPosition()[1] * 102.4 + 162);
            window->draw(playerSquare);
        }
}

void Zappy::Interface::fill_color_team()
{
    for (size_t i = 0; i <= _teamnbr; i++ and i <= color_list_team.size() ) {
        sf::Color color;
        color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
        color_list_team.push_back(color);
    }
}

void Zappy::Interface::print_players()
{
    for (int i = 0; i < _gui_connect->_players.size(); i++) {
        if (player_sprites.size() < _gui_connect->_players.size())
            player_sprites.push_back(sf::Sprite());
        player_sprites[i].setTexture(player_textures[_gui_connect->_players[i]->getLevel() - 1]);
        set_scale_of_player(i);
        player_sprites[i].setPosition(_gui_connect->_players[i]->getPosition()[0] * 102.4 + 100, _gui_connect->_players[i]->getPosition()[1] * 102.4 + 150);
        player_sprites[i].setTextureRect(player_orientation[_gui_connect->_players[i]->getLevel() - 1][_gui_connect->_players[i]->getOrientation() + 1]);
        window->draw(player_sprites[i]);
        // if (_gui_connect->_players[i]->getMessage() != "") {
        //     broadcast_texts.push_back(sf::Text(_gui_connect->_players[i]->getMessage(), font, 20));
        //     if (broadcast_texts.size() > 1) {
        //         broadcast_sprites.push_back(sf::Sprite());
        //         broadcast_sprites[broadcast_sprites.size() - 1].setTexture(broadcast_textures[0]);
        //         broadcast_sprites[broadcast_sprites.size() - 1].setPosition(_gui_connect->_players[i]->getPosition()[0] * 102.4 + 100, _gui_connect->_players[i]->getPosition()[1] * 102.4 + 130);
        //     }
        //     broadcast_texts[broadcast_texts.size() - 1].setPosition(_gui_connect->_players[i]->getPosition()[0] * 102.4 + 100, _gui_connect->_players[i]->getPosition()[1] * 102.4 + 130);
        //     broadcast_texts[broadcast_texts.size() - 1].setFillColor(sf::Color::Black);
        //     window->draw(broadcast_sprites[broadcast_sprites.size() - 1]);
        //     window->draw(broadcast_texts[broadcast_texts.size() - 1]);
        // }
        fill_color_team();
        print_player_team();
        // if (_gui_connect->_players[i]->isEvoluting()) {
        //     print_evolution(i);
        // }
    }
}

void Zappy::Interface::print_evolution(int current_player)
{
    sf::Sprite evolutionSprite;
    sf::Texture evolutionTexture;

    if (!evolutionTexture.loadFromFile("./sprite/animation/evo.png")) {
        std::cerr << "Error loading texture" << std::endl;
        return;
    }
    evolutionSprite.setTexture(evolutionTexture);
    set_scale_of_player(current_player);
    auto playerPosition = _gui_connect->_players[current_player]->getPosition();
    evolutionSprite.setPosition(playerPosition[0] * 102.4 + 100, playerPosition[1] * 102.4 + 150);
    window->draw(evolutionSprite);
}

Zappy::Interface::~Interface()
{
    window->close();
    if (_gui_connect != nullptr)
        _gui_connect->close_thread();
    if (ReceiveProcess.joinable())
        ReceiveProcess.join();
}

void Zappy::Interface::print_sound()
{
    if (sound_volume == 0)
        sound.setTextureRect(sf::IntRect(0, 360, 450, 325));
    else if (sound_volume < 75)
        sound.setTextureRect(sf::IntRect(895, 0, 450, 325));
    else if (sound_volume > 75 && sound_volume < 150)
        sound.setTextureRect(sf::IntRect(480, 20, 410, 325));
    else if (sound_volume > 150)
        sound.setTextureRect(sf::IntRect(0, 20, 450, 325));
}

void Zappy::Interface::set_map()
{
    for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        std::vector<std::shared_ptr<Tile>> tmp;
        std::vector<sf::Sprite> tmp_sprite;
        std::vector<sf::Sprite> tmp_iso_sprite;
        std::vector<std::vector<sf::Sprite>> tmp_ressource_sprite;
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            tmp.push_back(std::make_shared<Tile>(sf::Vector2f(i, j), std::make_shared<Inventory>()));
            int random_index = rand() % 6;
            tmp_sprite.push_back(tile_sprite_[random_index]);
            tmp_iso_sprite.push_back(tile_iso_sprite[random_index]);
            tmp_sprite[j].setPosition(i + 100, j + 100);
            tmp_ressource_sprite.push_back(ressource_sprite_);
        }
        _gui_connect->_tiles.push_back(tmp);
        map_sprites.push_back(tmp_sprite);
        map_iso_sprites.push_back(tmp_iso_sprite);
        ressource_sprite.push_back(tmp_ressource_sprite);
    }
}

void Zappy::Interface::print_resssource()
{
    for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            if (i < ressource_sprite.size() && j < ressource_sprite[i].size()) {
                ressource_sprite[i][j][6].setPosition(110 + (i * 102.4), 160 + (j * 102.4));
                if (_gui_connect->_tiles[i][j]->_inventory->get("Food") > 0) {
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Food") > 1)
                        ressource_sprite[i][j][6].setScale(0.05 * (_gui_connect->_tiles[i][j]->_inventory->get("Food")), 0.05 * (_gui_connect->_tiles[i][j]->_inventory->get("Food")));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][6]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Linemate") > 0) {
                    ressource_sprite[i][j][0].setPosition(130 + (i * 102.4), 160 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Linemate") > 1)
                        ressource_sprite[i][j][0].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Linemate")) * 0.5), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Linemate")) * 0.5));
                    else
                        ressource_sprite[i][j][0].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][0]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Deraumere") > 0) {
                    ressource_sprite[i][j][1].setPosition(160 + (i * 102.4), 160 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Deraumere") > 1)
                        ressource_sprite[i][j][1].setScale(0.025 * ((_gui_connect->_tiles[i][j]->_inventory->get("Deraumere")) * 0.75), 0.025 * ((_gui_connect->_tiles[i][j]->_inventory->get("Deraumere")) * 0.75));
                    else
                        ressource_sprite[i][j][1].setScale(0.025, 0.025);
                    window->draw(ressource_sprite[i][j][1]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Sibur") > 0) {
                    ressource_sprite[i][j][2].setPosition(160 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Sibur") > 1)
                        ressource_sprite[i][j][2].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Sibur")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Sibur")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][2]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Mendiane") > 0) {
                    ressource_sprite[i][j][3].setPosition(110 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Mendiane") > 1)
                        ressource_sprite[i][j][3].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Mendiane")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Mendiane")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][3]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Phiras") > 0) {
                    ressource_sprite[i][j][4].setPosition(120 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Phiras") > 1)
                        ressource_sprite[i][j][4].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Phiras")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Phiras")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][4]);
                }
                if (_gui_connect->_tiles[i][j]->_inventory->get("Thystame") > 0) {
                    ressource_sprite[i][j][5].setPosition(140 + (i * 102.4), 200 + (j * 102.4));
                    if (_gui_connect->_tiles[i][j]->_inventory->get("Thystame") > 1)
                        ressource_sprite[i][j][5].setScale(0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Thystame")) * 0.75), 0.05 * ((_gui_connect->_tiles[i][j]->_inventory->get("Thystame")) * 0.75));
                    else
                        ressource_sprite[i][j][6].setScale(0.05, 0.05);
                    window->draw(ressource_sprite[i][j][5]);
                }
            }
        }
    }
}

void Zappy::Interface::print_eggs()
{
    for (int i = 0; i < _gui_connect->_eggs.size(); i++) {
        if (egg_sprites.size() < _gui_connect->_eggs.size())
            egg_sprites.push_back(sf::Sprite());
        egg_sprites[i].setTexture(egg_texture);
        egg_sprites[i].setScale(0.05, 0.05);
        egg_sprites[i].setPosition(_gui_connect->_eggs[i]->getPosition()[0] * 102.4 + 135, _gui_connect->_eggs[i]->getPosition()[1] * 102.4 + 217);
        window->draw(egg_sprites[i]);
    }
}

void Zappy::Interface::check_event()
{
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        _inventory->check_event(&event, player_sprites, view);
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta > 0 && view.getSize().x > 1920 / 5 && view.getSize().y > 1080 / 5) {
                view.zoom(0.9);
                zoom += 1;
            } else if (event.mouseWheelScroll.delta < 0 && view.getSize().x < 1920 * 3 && view.getSize().y < 1080 * 3) {
                view.zoom(1.1);
                zoom -= 1;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 230 && event.mouseButton.x < 1920 - 230 && event.mouseButton.y > 75 && event.mouseButton.y < 1080 - 300) {
                isPanning = true;
                lastMousePos = sf::Mouse::getPosition(*window);
            }
            sf::Vector2f mousePos = window->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y), view);
            _info->Checkclick(mousePos);
        }
        sf::Vector2f mousePos2 = window->mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y), view);
        for (int i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (int j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                sf::FloatRect tileBounds2(100 + (i * 102.4), 150 + (j * 102.4), 102.4, 102.4);
                if (tileBounds2.contains(mousePos2)) {
                    rect.setPosition(tileBounds2.left, (tileBounds2.top - rect.getSize().y) + 102.4);
                    isOverTile = true;
                }
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                isPanning = false;
            }
        }
        if (event.type == sf::Event::MouseMoved) {
            if (isPanning) {
                sf::Vector2i currentMousePos = sf::Mouse::getPosition(*window);
                sf::Vector2f delta = window->mapPixelToCoords(lastMousePos) - window->mapPixelToCoords(currentMousePos);
                view.move(delta);
                lastMousePos = currentMousePos;
            }
        }
    }
}

void Zappy::Interface::print_map_iso()
{
    for (double i = 0; i < _gui_connect->get_size_map()[0]; i++) {
        for (double j = 0; j < _gui_connect->get_size_map()[1]; j++) {
            map_iso_sprites[i][j].setPosition(100 + (i * 102.4), 150 + (j * 102.4));
            window->draw(map_iso_sprites[i][j]);
        }
    }
}

void Zappy::Interface::loop(std::shared_ptr<GuiConnect> gui_connect)
{
    _gui_connect = gui_connect;
    this->_inventory.reset(new InventoryDisplay(_gui_connect, window));
    this->_info.reset(new InfoDisplay(_gui_connect, window, ressource_sprite_));
    ReceiveProcess = std::thread(&GuiConnect::receive, gui_connect.get());
    sleep(5);
    set_map();
    view.zoom(0.5);
    playBackgroundMusic("./asset/music/music.ogg");
    while (window->isOpen()) {
        window->clear(sf::Color::Black);
        sound_volume = bars[0]->checkClick(window);
        backgroundMusic.setVolume(sound_volume);
        check_event();
        window->setView(view); 
        for (double i = 0; i < _gui_connect->get_size_map()[0]; i++) {
            for (double j = 0; j < _gui_connect->get_size_map()[1]; j++) {
                map_sprites[i][j].setPosition(100 + (i * 102.4), 150 + (j * 102.4));
                window->draw(map_sprites[i][j]);
            }
        }
        if (isOverTile)
            window->draw(rect);
        for (size_t i = 0; i < gui_connect->getTeamNames().size(); i++) {
            Texts.push_back(sf::Text(gui_connect->getTeamNames()[i], font, 50));
            Texts[2 + i].setFillColor(sf::Color::Black);
            Texts[2 + i].setPosition(10, 50 + ((2 + i) * 50));
        }
        _teamnbr = gui_connect->getTeamNames().size();
        print_resssource();
        print_eggs();
        print_players();
        print_map_iso();
        window->setView(window->getDefaultView());
        for (size_t i = 0; i < _rect.size(); i++)
            window->draw(_rect[i]);
        for (size_t i = 0; i < Texts.size(); i++)
            window->draw(Texts[i]);
        tick = bars[1]->checkClick(window);
        if (tick > 2 && tick != last_tick) {
            _gui_connect->setTimeUnit(std::to_string(tick));
            last_tick = tick;
        }
        bars[0]->displayBar(window);
        bars[1]->displayBar(window);
        this->_inventory->display();
        window->draw(sound);
        _info->display();
        print_sound();
        window->display();
    }
}

void Zappy::Interface::command_handler()
{
}

void Zappy::Interface::playBackgroundMusic(const std::string& filename)
{
    if (!backgroundMusic.openFromFile(filename)) {
        std::cerr << "Error loading music file: " << filename << std::endl;
        return;
    }
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}
