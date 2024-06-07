/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_pin
*/

#include "../gui_include.hpp"

Test(pin, test_pin_askCommand_no_throw)
{
    Zappy::PIN pin;
    std::vector<std::string> args = {"2"};
    cr_assert_no_throw(pin.askCommand(1, args), Zappy::CommandError);
}

Test(pin, test_pin_askCommand_throw)
{
    Zappy::PIN pin;
    std::vector<std::string> args = {"1", "2", "3"};
    cr_assert_throw(pin.askCommand(1, args), Zappy::CommandError);
}

Test(pin, test_pin_apply_changes_throw)
{
    Zappy::PIN pin;
    std::vector<std::string> parsedData = {"pin", "2", "3", "13", "4", "5", "6"};
    std::array<int, 2> size_map = {10, 10};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    int timeUnit = 1;
    bool isRunning = true;
    cr_assert_throw(pin.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(pin, test_pin_apply_changes)
{
    Zappy::PIN pin;
    std::vector<std::string> parsedData = {"pin", "2", "3", "13", "4", "5", "6", "7", "8", "9", "10"};
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
    cr_assert_no_throw(pin.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(players.size(), 1);
    cr_assert_eq(players[0]->getPlayerNumber(), 2);
    cr_assert_eq(players[0]->getInventory()->get("Food"), 4);
    cr_assert_eq(players[0]->getInventory()->get("Linemate"), 5);
    cr_assert_eq(players[0]->getInventory()->get("Deraumere"), 6);
    cr_assert_eq(players[0]->getInventory()->get("Sibur"), 7);
    cr_assert_eq(players[0]->getInventory()->get("Mendiane"), 8);
    cr_assert_eq(players[0]->getInventory()->get("Phiras"), 9);
    cr_assert_eq(players[0]->getInventory()->get("Thystame"), 10);
}
