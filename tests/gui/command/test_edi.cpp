/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_edi
*/

#include "../gui_include.hpp"

Test(EDI, applyChanges_invalid_args)
{
    Zappy::EDI edi;
    std::vector<std::string> parsedData = {"edi", "2", "3", "7"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    bool isRunning = true;

    cr_assert_throw(edi.applyChanges(parsedData, size_map, tiles, players, eggs, teams, 1, isRunning), Zappy::CommandError);
}

Test(EDI, applyChanges_invalid_egg_number)
{
    Zappy::EDI edi;
    std::vector<std::string> parsedData = {"edi", "azeaeaze"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
    egg->setPlayerNumber(2);
    egg->setTeamName("team1");
    eggs.push_back(egg);
    std::vector<std::string> teams;
    bool isRunning = true;

    cr_assert_throw(edi.applyChanges(parsedData, size_map, tiles, players, eggs, teams, 1, isRunning), Zappy::CommandError);
}

Test(EDI, applyChanges)
{
    Zappy::EDI edi;
    std::vector<std::string> parsedData = {"edi", "2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
    bool isRunning = true;

    egg->setPlayerNumber(2);
    egg->setTeamName("team1");
    eggs.push_back(egg);
    edi.applyChanges(parsedData, size_map, tiles, players, eggs, teams, 1, isRunning);
    cr_assert_eq(eggs.size(), 0);
}