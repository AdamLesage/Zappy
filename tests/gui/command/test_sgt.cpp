/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_sgt
*/

#include "../gui_include.hpp"

Test(SGT, askCommand)
{
    Zappy::SGT sgt;
    std::vector<std::string> args = {"sgt"};
    int fd = 0;

    cr_assert_no_throw(sgt.askCommand(fd, args), Zappy::CommandError);
}

Test(SGT, askCommandError)
{
    Zappy::SGT sgt;
    std::vector<std::string> args = {"sgt", "2"};
    int fd = 0;

    cr_assert_throw(sgt.askCommand(fd, args), Zappy::CommandError);
}

Test(SGT, applyChanges_invalid_args)
{
    Zappy::SGT sgt;
    std::vector<std::string> parsedData = {"sgt", "2", "3", "7"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_throw(sgt.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(SGT, applyChanges)
{
    Zappy::SGT sgt;
    std::vector<std::string> parsedData = {"sgt", "2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_no_throw(sgt.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(timeUnit, 2);
}

Test(SGT, applyChanges_invalid_timeUnit)
{
    Zappy::SGT sgt;
    std::vector<std::string> parsedData = {"sgt", "ezaeaz2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_throw(sgt.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}
