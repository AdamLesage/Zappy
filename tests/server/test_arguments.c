/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_arguments
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_arguments, not_enough_arguments, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", NULL};
    int argc = 1;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: not enough arguments\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, missing_mandatory_flags, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: missing mandatory flag\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, unknown_flag, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-z", "10", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: unknow flag\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

//// -p flag test ////

Test(get_arguments, no_port_number, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: port number not found\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, no_port_number2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", "-p", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: port number not found\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, invalide_port_number, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "abcd", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: port must be a number\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, invalie_port_number2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "0", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: port must be > 0\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}


//// -x flag test ////

Test(get_arguments, no_x_number, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: width must be a number\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, no_x_number2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", "-x", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: width must be a number\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, invalide_x_number, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "abc", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: width must be a number\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

Test(get_arguments, invalie_x_number2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "0", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
    cr_assert_stderr_eq_str("Error: width must be > 1\nUSAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
}

//// -f flag test ////

Test(get_arguments, no_y_number, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, no_y_number2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-n", "team1", "team2", "-c", "5", "-f", "100", "-y", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, invalide_y_number, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "abc", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, invalie_y_number2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "0", "-n", "team1", "team2", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

//// -n flag test ////

Test(get_arguments, no_team_name, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-c", "5", "-f", "100", "-n", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, no_team_name2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "-c", "5", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

//// -c flag test ////

Test(get_arguments, no_nb_client, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, no_nb_client2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, invalid_nb_client, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "abc", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, invalide_nb_client2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "0", "-f", "100", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

//// -f flag ////

Test(get_arguments, no_frequency_found, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, invalide_frequency, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "abc", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

Test(get_arguments, invalide_frequency2, .init = redirect_all_stdout, .exit_code = 84) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "1", NULL};
    int argc = 5;

    get_arguments(&arguments, argc, argv);
}

//// valide test /////
Test(get_arguments, valid_arguments, .init = redirect_all_stdout) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", "-f", "150", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    cr_assert_eq(arguments.port, 4242);
    cr_assert_eq(arguments.frequency, 150);
    cr_assert_eq(arguments.width, 10);
    cr_assert_eq(arguments.height, 20);
    cr_assert_eq(arguments.nb_client, 5);
    cr_assert_eq(arguments.nb_teams, 2);
    cr_assert_str_eq(arguments.name_teams[0], "team1");
    cr_assert_str_eq(arguments.name_teams[1], "team2");
}

Test(get_arguments, frequency_default, .init = redirect_all_stdout) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "20", "-n", "team1", "team2", "-c", "5", NULL};
    int argc = 12;

    get_arguments(&arguments, argc, argv);
    cr_assert_eq(arguments.port, 4242);
    cr_assert_eq(arguments.frequency, 100);
    cr_assert_eq(arguments.width, 10);
    cr_assert_eq(arguments.height, 20);
    cr_assert_eq(arguments.nb_client, 5);
    cr_assert_eq(arguments.nb_teams, 2);
    cr_assert_str_eq(arguments.name_teams[0], "team1");
    cr_assert_str_eq(arguments.name_teams[1], "team2");
}

Test(get_arguments, multiple_teams, .init = redirect_all_stdout) {
    arguments_t arguments;
    const char *argv[] = {"./zappy_server", "-p", "4242", "-x", "15", "-y", "25", "-n", "team1", "team2", "team3", "-c", "3", "-f", "50", NULL};
    int argc = 13;

    get_arguments(&arguments, argc, argv);
    cr_assert_eq(arguments.port, 4242);
    cr_assert_eq(arguments.width, 15);
    cr_assert_eq(arguments.height, 25);
    cr_assert_eq(arguments.nb_teams, 3);
    cr_assert_eq(arguments.nb_client, 3);
    cr_assert_eq(arguments.frequency, 50);
    cr_assert_str_eq(arguments.name_teams[0], "team1");
    cr_assert_str_eq(arguments.name_teams[1], "team2");
    cr_assert_str_eq(arguments.name_teams[2], "team3");
}