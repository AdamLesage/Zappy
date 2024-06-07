/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_seg
*/

#include "../gui_include.hpp"

Test(SEG, applyChanges_invalid_args)
{
    Zappy::SEG seg;
    std::vector<std::string> parsedData = {"seg", "2", "3", "7"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_throw(seg.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(SEG, applyChanges)
{
    Zappy::SEG seg;
    std::vector<std::string> parsedData = {"seg", "2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    seg.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning);
    cr_assert_eq(isRunning, false);
}
