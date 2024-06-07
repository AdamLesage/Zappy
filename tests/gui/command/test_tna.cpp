/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_tna
*/

#include "../gui_include.hpp"

Test(TNA, askCommand_invalid_args)
{
    Zappy::TNA tna;
    std::vector<std::string> args = {"tna", "2"};
    int fd = 0;

    cr_assert_throw(tna.askCommand(fd, args), Zappy::CommandError);
}

Test(TNA, askCommand)
{
    Zappy::TNA tna;
    std::vector<std::string> args = {"tna"};
    int fd = 0;

    cr_assert_throw(tna.askCommand(fd, args), Zappy::CommandError);
}

Test(TNA, applyChanges_invalid_args)
{
    Zappy::TNA tna;
    std::vector<std::string> parsedData = {"tna"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_throw(tna.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
}

Test(TNA, applyChanges)
{
    Zappy::TNA tna;
    std::vector<std::string> parsedData = {"tna", "team1", "team2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_no_throw(tna.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(teams.size(), 2);
    cr_assert_str_eq(teams[0].c_str(), "team1");
    cr_assert_str_eq(teams[1].c_str(), "team2");
}


Test(TNA, applyChangesErrorThrow)
{
    Zappy::TNA tna;
    std::vector<std::string> parsedData = {"tna", "team1", "team2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;
    int timeUnit = 1;

    cr_assert_no_throw(tna.applyChanges(parsedData, size_map, tiles, players, eggs, teams, timeUnit, isRunning), Zappy::CommandError);
    cr_assert_eq(teams.size(), 2);
    cr_assert_str_eq(teams[0].c_str(), "team1");
    cr_assert_str_eq(teams[1].c_str(), "team2");
}

Test(TNA, receiveDataInvalidName)
{
    Zappy::TNA tna;
    std::string message = "tna 2\n team1\n team2\n";
    std::string commandName = "tna2";
    std::vector<std::string> teams;

    teams = tna.receiveData(message, commandName);
    cr_assert_eq(teams.size(), 0);
}

Test(TNA, receiveData)
{
    Zappy::TNA tna;
    std::string message = "tna team1\ntna team2\n";
    std::string commandName = "tna";
    std::vector<std::string> teams;

    teams = tna.receiveData(message, commandName);
    cr_assert_eq(teams.size(), 2);
    cr_assert_str_eq(teams[0].c_str(), "team1");
    cr_assert_str_eq(teams[1].c_str(), "team2");
}
