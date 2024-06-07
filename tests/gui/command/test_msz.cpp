/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_msz
*/

#include "../gui_include.hpp"

Test(msz, test_msz_askCommand_no_throw)
{
    Zappy::MSZ msz;
    std::vector<std::string> args = {"msz\n"};
    cr_assert_no_throw(msz.askCommand(1, args), Zappy::CommandError);
}

Test(msz, test_msz_askCommand_throw)
{
    Zappy::MSZ msz;
    std::vector<std::string> args = {"1", "2"};
    cr_assert_throw(msz.askCommand(1, args), Zappy::CommandError);
}

Test(msz, test_msz_apply_changes_throw)
{
    Zappy::MSZ msz;
    std::vector<std::string> parsedData = {"msz", "2", "3", "1", "2", "3", "4", "5", "6"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(msz.applyChanges(parsedData, size_map, tiles, players, eggs, timeUnit, isRunning), Zappy::CommandError);
}

Test(msz, test_msz_apply_changes_empty_map)
{
    Zappy::MSZ msz;
    std::vector<std::string> parsedData = {"msz", "2", "3"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_no_throw(msz.applyChanges(parsedData, size_map, tiles, players, eggs, timeUnit, isRunning), Zappy::CommandError);
}

Test(msz, test_msz_apply_changes)
{
    Zappy::MSZ msz;
    std::vector<std::string> parsedData = {"msz", "2", "3"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    msz.applyChanges(parsedData, size_map, tiles, players, eggs, timeUnit, isRunning);
    cr_assert_eq(size_map[0], 2);
    cr_assert_eq(size_map[1], 3);
}