/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_bct
*/

#include "../gui_include.hpp"

Test(bct, test_bct_askCommand_no_throw)
{
    Zappy::BCT bct;
    std::vector<std::string> args = {"bct", "2", "3"};
    cr_assert_no_throw(bct.askCommand(1, args), Zappy::CommandError);
}

Test(bct, test_bct_askCommand_throw)
{
    Zappy::BCT bct;
    std::vector<std::string> args = {"1", "2"};
    cr_assert_throw(bct.askCommand(1, args), Zappy::CommandError);
}

Test(bct, test_bct_apply_changes_throw)
{
    Zappy::BCT bct;
    std::vector<std::string> parsedData = {"bct", "2", "3", "1", "2", "3", "4", "5", "6"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(bct.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(bct, test_bct_apply_changes_empty_map)
{
    Zappy::BCT bct;
    std::vector<std::string> parsedData = {"bct", "2", "3", "1", "2", "3", "4", "5", "6", "7"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_no_throw(bct.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(bct, test_bct_apply_changes)
{
    Zappy::BCT bct;
    std::vector<std::string> parsedData = {"bct", "2", "3", "1", "2", "3", "4", "5", "6", "7"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    for (int i = 0; i < size_map[0]; i++)
    {
        std::vector<std::shared_ptr<Zappy::Tile>> tmp;
        for (int j = 0; j < size_map[1]; j++)
        {
            tmp.push_back(std::make_shared<Zappy::Tile>(sf::Vector2f(i, j), std::make_shared<Zappy::Inventory>()));
        }
        tiles.push_back(tmp);
    }
    bct.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning);
    cr_assert_eq(tiles.size(), 10);
    cr_assert_eq(tiles[3][2]->_inventory->get("Food"), 1);
    cr_assert_eq(tiles[3][2]->_inventory->get("Linemate"), 2);
    cr_assert_eq(tiles[3][2]->_inventory->get("Deraumere"), 3);
    cr_assert_eq(tiles[3][2]->_inventory->get("Sibur"), 4);
    cr_assert_eq(tiles[3][2]->_inventory->get("Mendiane"), 5);
    cr_assert_eq(tiles[3][2]->_inventory->get("Phiras"), 6);
    cr_assert_eq(tiles[3][2]->_inventory->get("Thystame"), 7);
}
