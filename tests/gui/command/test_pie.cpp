/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_pie
*/

#include "../gui_include.hpp"

Test(pie, test_pie_apply_changes_throw)
{
    Zappy::PIE pie;
    std::vector<std::string> parsedData = {"pie", "2", "3", "1", "2", "3", "4", "5", "6"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(pie.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(pie, test_pie_apply_changes_result_ok)
{
    Zappy::PIE pie;
    std::vector<std::string> parsedData = {"pie", "2", "3", "ok"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    std::shared_ptr<Zappy::Player> player2 = std::make_shared<Zappy::Player>();
    std::vector<std::string> teams;
    player->setPlayerNumber(2);
    player2->setPlayerNumber(3);
    player->setPlayerLevel(1);
    player2->setPlayerLevel(1);
    player->setPosition(2, 3);
    player2->setPosition(2, 3);
    player->setIsIncanting(true);
    player2->setIsIncanting(true);
    players.push_back(player);
    players.push_back(player2);
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_no_throw(pie.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(players.size(), 2);
    cr_assert_eq(players[0]->getPlayerNumber(), 2);
    cr_assert_eq(players[0]->getLevel(), 2);
    cr_assert_eq(players[0]->isPlayerIncanting(), false);
    cr_assert_eq(players[1]->getPlayerNumber(), 3);
    cr_assert_eq(players[1]->getLevel(), 2);
    cr_assert_eq(players[1]->isPlayerIncanting(), false);
}

Test(pie, test_pie_apply_changes_result_failed)
{
    Zappy::PIE pie;
    std::vector<std::string> parsedData = {"pie", "2", "3", "ko"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    std::shared_ptr<Zappy::Player> player2 = std::make_shared<Zappy::Player>();
    std::vector<std::string> teams;
    player->setPlayerNumber(2);
    player->setPlayerLevel(1);
    player->setPosition(2, 3);
    player->setIsIncanting(true);
    players.push_back(player);
    player2->setPlayerNumber(3);
    player2->setPlayerLevel(1);
    player2->setPosition(2, 3);
    player2->setIsIncanting(true);
    players.push_back(player2);
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_no_throw(pie.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(players.size(), 2);
    cr_assert_eq(players[0]->getPlayerNumber(), 2);
    cr_assert_eq(players[0]->getLevel(), 1);
    cr_assert_eq(players[0]->isPlayerIncanting(), false);
    cr_assert_eq(players[1]->getPlayerNumber(), 3);
    cr_assert_eq(players[1]->getLevel(), 1);
    cr_assert_eq(players[1]->isPlayerIncanting(), false);
}

Test(pie, test_pie_apply_changes_invalid_input)
{
    Zappy::PIE pie;
    std::vector<std::string> parsedData = {"pie", "eaz2", "3", "ko"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    std::shared_ptr<Zappy::Player> player2 = std::make_shared<Zappy::Player>();
    std::vector<std::string> teams;
    player->setPlayerNumber(2);
    player->setPlayerLevel(1);
    player->setPosition(2, 3);
    player->setIsIncanting(true);
    players.push_back(player);
    player2->setPlayerNumber(3);
    player2->setPlayerLevel(1);
    player2->setPosition(2, 3);
    player2->setIsIncanting(true);
    players.push_back(player2);
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(pie.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}
