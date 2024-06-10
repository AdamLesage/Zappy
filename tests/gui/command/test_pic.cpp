/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_pic
*/

#include "../gui_include.hpp"

Test(PIC, applyChanges_invalid_args)
{
    std::vector<std::string> parsedData = {"1", "Hello"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PIC pic;
    cr_assert_throw(pic.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PIC, applyChanges)
{
    std::vector<std::string> parsedData = {"pic", "1", "1", "2", "1", "1", "1", "1", "1"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    player->setPlayerNumber(1);
    players.push_back(player);
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PIC pic;
    cr_assert_no_throw(pic.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(player->isPlayerIncanting(), true);
}

Test(PIC, applyChanges_throw_error)
{
    std::vector<std::string> parsedData = {"pic", "1", "1", "2", "zeaea1", "1", "1", "1", "1"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    player->setPlayerNumber(1);
    players.push_back(player);
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PIC pic;
    cr_assert_throw(pic.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}
