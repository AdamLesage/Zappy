/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_ppo
*/

#include "../gui_include.hpp"

Test(ppo, test_ppo_askCommand_no_throw)
{
    Zappy::PPO ppo;
    std::vector<std::string> args = {"ppo", "2"};
    cr_assert_no_throw(ppo.askCommand(1, args), Zappy::CommandError);
}

Test(ppo, test_ppo_askCommand_throw)
{
    Zappy::PPO ppo;
    std::vector<std::string> args = {"1", "2", "3"};
    cr_assert_throw(ppo.askCommand(1, args), Zappy::CommandError);
}


Test(ppo, test_ppo_apply_changes_throw)
{
    Zappy::PPO ppo;
    std::vector<std::string> parsedData = {"ppo", "2", "3", "1", "2", "3", "4", "5", "6"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(ppo.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(ppo, test_ppo_apply_changes_empty_map)
{
    Zappy::PPO ppo;
    std::vector<std::string> parsedData = {"ppo", "2", "3", "1", "2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::shared_ptr<Zappy::Player> player = std::make_shared<Zappy::Player>();
    player->setPlayerNumber(2);
    players.push_back(player);
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_no_throw(ppo.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(players.size(), 1);
    cr_assert_eq(players[0]->getPlayerNumber(), 2);
    cr_assert_eq(players[0]->getPosition()[0], 3);
    cr_assert_eq(players[0]->getPosition()[1], 1);
    cr_assert_eq(players[0]->getOrientation(), 2);
}