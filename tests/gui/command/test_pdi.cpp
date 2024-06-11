/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_pdi
*/

#include "../gui_include.hpp"

Test(PDI, applyChanges_invalid_args)
{
    std::vector<std::string> parsedData = {"1", "Hello", "zae"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PDI pdi;
    cr_assert_throw(pdi.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PDI, applyChanges_player_not_found)
{
    std::vector<std::string> parsedData = {"pdi", "1",};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PDI pdi;
    cr_assert_throw(pdi.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PDI, applyChanges)
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
    player->setInventory(inventory);
    players.push_back(player);

    Zappy::PDI pdi;
    std::vector<std::string> parsedData = {"pdi", "1"};
    pdi.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning);
    cr_assert_eq(players.size(), 0);
}

Test(PDI, applyChanges_invalid_player_number)
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
    player->setInventory(inventory);
    players.push_back(player);

    Zappy::PDI pdi;
    std::vector<std::string> parsedData = {"pdi", "papapa"};
    cr_assert_throw(pdi.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}
