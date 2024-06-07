/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_mct
*/

#include "../gui_include.hpp"

Test(MCT, askCommand_invalid_args)
{
    Zappy::MCT mct;
    int fd = 1;
    std::vector<std::string> args = {"mct", "azeazeaze"};

    cr_assert_throw(mct.askCommand(fd, args), Zappy::CommandError);
}

Test(MCT, askCommand)
{
    Zappy::MCT mct;
    int fd = 1;
    std::vector<std::string> args = {"mct"};

    cr_redirect_stdout();
    cr_assert_no_throw(mct.askCommand(fd, args), Zappy::CommandError);
}
