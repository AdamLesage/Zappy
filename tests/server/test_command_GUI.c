/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_command_GUI
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(msz, test_msz)
{
    core_t core;
    char *command[] = {"msz", NULL};
    char *team_names[] = {"team1", "team2", NULL};
    char *expected = "msz 10 10\n";

    core.map.width = 10;
    core.map.height = 10;
    msz(&core, 0, command);
    cr_assert_stdout_eq_str(expected);
}

Test(tna, test_tna)
{
    core_t core;
    char *command[] = {"tna", NULL};
    char *team_names[] = {"team1", "team2", NULL};
    char *expected = "tna team1\ntna team2\n";

    core.arguments.name_teams = team_names;
    core.arguments.nb_teams = 2;
    tna(&core, 0, command);
    cr_assert_stdout_eq_str(expected);
}