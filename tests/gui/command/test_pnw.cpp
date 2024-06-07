/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_pnw
*/

#include "../gui_include.hpp"

Test(pnw, test_pnw_apply_changes_throw)
{
    Zappy::PNW pnw;
    std::vector<std::string> parsedData = {"pnw", "2", "3", "1", "2", "3", "4", "5", "6"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(pnw.applyChanges(parsedData, size_map, tiles, players, eggs, timeUnit, isRunning), Zappy::CommandError);
}

Test(pnw, test_pnw_apply_changes)
{
    Zappy::PNW pnw;
    std::vector<std::string> parsedData = {"pnw", "2", "3", "1", "2", "3", "4"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_no_throw(pnw.applyChanges(parsedData, size_map, tiles, players, eggs, timeUnit, isRunning), Zappy::CommandError);
}
