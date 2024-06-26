/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_pdr
*/

#include "../gui_include.hpp"

Test(PDR, applyChanges_invalid_args)
{
    std::vector<std::string> parsedData = {"1", "Hello"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PDR pdr;
    cr_assert_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PDR, applyChanges_player_not_found)
{
    std::vector<std::string> parsedData = {"pdr", "1", "1"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PDR pdr;
    cr_assert_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PDR, applyChanges_invalid_resource)
{
    std::vector<std::string> parsedData = {"pdr", "1", "71"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    player->setPlayerNumber(1);
    player->setPosition(1, 1);
    player->setTeamName("Team1");
    std::shared_ptr<Zappy::Inventory> inventory = std::make_shared<Zappy::Inventory>();
    inventory->set("Food", 1);
    player->setInventory(inventory);
    players.push_back(player);

    Zappy::PDR pdr;
    cr_assert_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PDR, applyChanges)
{
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    player->setPlayerNumber(1);
    player->setPosition(1, 1);
    player->setTeamName("Team1");
    std::shared_ptr<Zappy::Inventory> inventory = std::make_shared<Zappy::Inventory>();
    inventory->set("Food", 1);
    inventory->set("Linemate", 1);
    inventory->set("Deraumere", 1);
    inventory->set("Sibur", 1);
    inventory->set("Mendiane", 1);
    inventory->set("Phiras", 1);
    inventory->set("Thystame", 1);
    player->setInventory(inventory);
    players.push_back(player);

    Zappy::PDR pdr;
    for (int i = 0; i < size_map[0]; i++)
    {
        std::vector<std::shared_ptr<Zappy::Tile>> tmp;
        for (int j = 0; j < size_map[1]; j++)
        {
            tmp.push_back(std::make_shared<Zappy::Tile>(sf::Vector2f(i, j), std::make_shared<Zappy::Inventory>()));
        }
        tiles.push_back(tmp);
    }
    std::vector<std::string> parsedData = {"pdr", "1", "0"}; // Food
    cr_assert_no_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(tiles[1][1]->_inventory->get("Food"), 1);
    cr_assert_eq(player->getInventory()->get("Food"), 0);
    parsedData = {"pdr", "1", "1"}; // Linemate
    cr_assert_no_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    std::cout << "Tile inventory: " << tiles[1][1]->_inventory->get("Linemate") << std::endl;
    cr_assert_eq(tiles[1][1]->_inventory->get("Linemate"), 1);
    cr_assert_eq(player->getInventory()->get("Linemate"), 0);
    parsedData = {"pdr", "1", "2"}; // Deraumere
    cr_assert_no_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(tiles[1][1]->_inventory->get("Deraumere"), 1);
    cr_assert_eq(player->getInventory()->get("Deraumere"), 0);
    parsedData = {"pdr", "1", "3"}; // Sibur
    cr_assert_no_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(tiles[1][1]->_inventory->get("Sibur"), 1);
    cr_assert_eq(player->getInventory()->get("Sibur"), 0);
    parsedData = {"pdr", "1", "4"}; // Mendiane
    cr_assert_no_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(tiles[1][1]->_inventory->get("Mendiane"), 1);
    cr_assert_eq(player->getInventory()->get("Mendiane"), 0);
    parsedData = {"pdr", "1", "5"}; // Phiras
    cr_assert_no_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(tiles[1][1]->_inventory->get("Phiras"), 1);
    cr_assert_eq(player->getInventory()->get("Phiras"), 0);
    parsedData = {"pdr", "1", "6"}; // Thystame
    cr_assert_no_throw(pdr.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(tiles[1][1]->_inventory->get("Thystame"), 1);
    cr_assert_eq(player->getInventory()->get("Thystame"), 0);
}