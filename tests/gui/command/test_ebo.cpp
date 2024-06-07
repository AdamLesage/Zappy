/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_ebo
*/

#include "../gui_include.hpp"

Test(EBO, applyChanges_invalid_args)
{
    Zappy::EBO ebo;
    std::vector<std::string> parsedData = {"ebo", "2", "3", "7"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
    bool isRunning = true;
    egg->setPlayerNumber(2);
    egg->setTeamName("team1");
    egg->setPosition(2, 3);
    eggs.push_back(egg);

    cr_assert_throw(ebo.applyChanges(parsedData, size_map, tiles, players, eggs, teams, 1, isRunning), Zappy::CommandError);
}

Test(EBO, applyChanges_invalid_egg_number)
{
    Zappy::EBO ebo;
    std::vector<std::string> parsedData = {"ebo", "azeaeaze"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
    bool isRunning = true;
    egg->setPlayerNumber(2);
    egg->setTeamName("team1");
    egg->setPosition(2, 3);
    eggs.push_back(egg);

    cr_assert_throw(ebo.applyChanges(parsedData, size_map, tiles, players, eggs, teams, 1, isRunning), Zappy::CommandError);
}

Test(EBO, applyChanges)
{
    Zappy::EBO ebo;
    std::vector<std::string> parsedData = {"ebo", "2"};
    std::array<int, 2> size_map = {0, 0};
    std::vector<std::vector<std::shared_ptr<Zappy::Tile>>> tiles;
    std::vector<std::shared_ptr<Zappy::Player>> players;
    std::vector<std::shared_ptr<Zappy::Egg>> eggs;
    std::vector<std::string> teams;
    std::shared_ptr<Zappy::Egg> egg = std::make_shared<Zappy::Egg>();
    bool isRunning = true;
    egg->setPlayerNumber(2);
    egg->setTeamName("team1");
    egg->setPosition(2, 3);
    eggs.push_back(egg);

    ebo.applyChanges(parsedData, size_map, tiles, players, eggs, teams, 1, isRunning);
    cr_assert_eq(players.size(), 1);
    cr_assert_eq(eggs.size(), 0);
    cr_assert_eq(players[0]->getPlayerNumber(), 2);
    cr_assert_eq(players[0]->getTeamName(), "team1");
    cr_assert_eq(players[0]->getPosition()[0], 2);
    cr_assert_eq(players[0]->getPosition()[1], 3);
    cr_assert_eq(players[0]->getLevel(), 1);
    cr_assert_eq(players[0]->getOrientation(), 0);
    cr_assert_eq(players[0]->getMessage(), "");
}
