/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui_connect
*/

#include "gui_connect.hpp"
#include "ConnectError.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

GuiConnect::GuiConnect()
{
    _socket = 0;
    _port = 0;
}

GuiConnect::GuiConnect(std::string port, std::string machine)
{
    try {
        this->_port = std::stoi(port);
    } catch (const std::invalid_argument& e) {
        throw Zappy::ConnectError("Invalid port", "GuiConnect");
    }
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    if (_socket == -1) {
        throw Zappy::ConnectError("Failed to create socket", "GuiConnect");
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(_port);
    inet_pton(AF_INET, machine.c_str(), &serv_addr.sin_addr);
    if (connect(_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        throw Zappy::ConnectError("Failed to connect to server", "GuiConnect");
        close(_socket);
    }
}

void GuiConnect::send(std::string message)
{
    printf("need to be done");
}

void GuiConnect::receive()
{
    char buffer[1024] = {0};

    if (read(_socket, buffer, 1024) == -1) {
        throw Zappy::ConnectError("Failed to receive message", "GuiConnect");
    }
    std::cout << buffer << std::endl;
}

void GuiConnect::close_socket()
{
    close(_socket);
}