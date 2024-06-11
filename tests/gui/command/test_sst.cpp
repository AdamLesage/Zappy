/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_sst
*/

#include "../gui_include.hpp"


Test(SST, askCommand)
{
    Zappy::SST sst;
    std::vector<std::string> args = {"sst"};
    int fd = 0;

    cr_assert_throw(sst.askCommand(fd, args), Zappy::CommandError);
}

Test(SST, askCommandError)
{
    Zappy::SST sst;
    std::vector<std::string> args = {"sst", "2"};
    int fd = 0;

    cr_assert_no_throw(sst.askCommand(fd, args), Zappy::CommandError);
}

Test(SST, applyChanges_invalid_args)
{
    Zappy::SST sst;
    std::vector<std::string> parsedData = {"sst", "2", "3", "7"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_throw(sst.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(SST, applyChanges)
{
    Zappy::SST sst;
    std::vector<std::string> parsedData = {"sst", "2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_no_throw(sst.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(timeUnit, 2);
}

Test(SST, applyChanges_invalid_timeUnit)
{
    Zappy::SST sst;
    std::vector<std::string> parsedData = {"sst", "ezaeaz2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_throw(sst.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}
