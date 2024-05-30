/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui_connect
*/

#include "gui_connect.hpp"
#include "ConnectError.hpp"

GuiConnect::GuiConnect()
{
    _socket = 0;
    _port = 0;
}

GuiConnect::GuiConnect(std::string port)
{
    try {
        this->_port = std::stoi(port);
        printf("Port: %d\n", this->_port);
    } catch (const std::invalid_argument& e) {
        throw Zappy::ConnectError("Invalid port", "GuiConnect");
    }
}

void send(int socket, std::string message)
{
}