/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_enw
*/

#include "../gui_include.hpp"

Test(ENW, test_enw_askCommand_no_throw)
{
    Zappy::ENW enw;
    std::vector<std::string> args = {"enw", "2", "3"};
    cr_assert_no_throw(enw.askCommand(1, args), Zappy::CommandError);
}

Test(ENW, test_enw_askCommand_throw)
{
    Zappy::ENW enw;
    std::vector<std::string> args = {"1", "2"};
    cr_assert_throw(enw.askCommand(1, args), Zappy::CommandError);
}

Test(ENW, test_enw_apply_changes_throw)
{
    Zappy::ENW enw;
    std::vector<std::string> parsedData = {"enw", "2", "3", "1", "2", "3", "4", "5", "6"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(enw.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}
