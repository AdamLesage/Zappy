/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_pfk
*/

#include "../gui_include.hpp"

Test(PFK, applyChanges_invalid_args)
{
    std::vector<std::string> parsedData = {"1", "Hello", "zeaea"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PFK pfk;
    cr_assert_throw(pfk.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PFK, applyChanges_player_not_found)
{
    std::vector<std::string> parsedData = {"pfk", "1"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 100;
    bool isRunning = true;

    Zappy::PFK pfk;
    cr_assert_throw(pfk.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(PFK, applyChanges)
{
    std::vector<std::string> parsedData = {"pfk", "1"};
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
    players.push_back(player);

    Zappy::PFK pfk;
    cr_assert_no_throw(pfk.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}
