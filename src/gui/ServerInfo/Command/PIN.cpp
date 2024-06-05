/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** PIN
*/

#include "PIN.hpp"

Zappy::PIN::PIN()
{
}

Zappy::PIN::~PIN()
{
}

void Zappy::PIN::askCommand(int socket, std::vector<std::string> args)
{
    std::string command = "pin " + args[0] + "\n";
    write(socket, command.c_str(), command.length());
}

std::vector<std::string> Zappy::PIN::receiveData(std::string message)
{
    if (strncmp(message.c_str(), "pin", 3))
        return {};
    std::vector<std::string> args = my_str_to_word_array((char *)message.c_str());
    std::vector<std::string> data;
    std::string player_nb = args[1];
    std::string x_pos = args[2];
    std::string y_pos = args[3];
    std::string food_quantity = args[4];
    std::string linemate_quantity = args[5];
    std::string deraumere_quantity = args[6];
    std::string sibur_quantity = args[7];
    std::string mendiane_quantity = args[8];
    std::string phiras_quantity = args[9];
    std::string thystame_quantity = args[10];

    data.push_back("pin");
    data.push_back(player_nb);
    data.push_back(x_pos);
    data.push_back(y_pos);
    data.push_back(food_quantity);
    data.push_back(linemate_quantity);
    data.push_back(deraumere_quantity);
    data.push_back(sibur_quantity);
    data.push_back(mendiane_quantity);
    data.push_back(phiras_quantity);
    data.push_back(thystame_quantity);
    // return format std::vector<std::string> { "pin", "player_nb", "x_pos", "y_pos", "food quantity", "linemate quantity", "deraumere quantity", "sibur quantity", "mendiane quantity", "phiras quantity", "thystame quantity" };
    return data;
}