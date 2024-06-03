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
#include <vector>

std::vector<std::string> my_str_to_line_array(char *str);
std::vector<std::string> my_str_to_word_array(const char *str);

GuiConnect::GuiConnect()
{
    _socket = 0;
    _port = 0;
    Running = true;
    _size_map[0] = 0;
    _size_map[1] = 0;
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
    if (write(_socket, message.c_str(), message.size()) == -1) {
        throw Zappy::ConnectError("Failed to send message", "GuiConnect");
    }

}

void GuiConnect::receive()
{
    char buffer[1024] = {0};

    while (Running) {
        if (read(_socket, buffer, 1024) == -1) {
            throw Zappy::ConnectError("Failed to receive message", "GuiConnect");
        }
        printf("Received: %s\n", buffer);
        std::vector<std::string> pString = my_str_to_line_array(buffer);
        for (size_t i = 0; i < pString.size(); i++) {
            if (strncmp(pString[i].c_str(), "msz", 3) == 0) {
                std::vector<std::string> pString2 = my_str_to_word_array(pString[i].c_str());
                _size_map[0] = std::stoi(pString2[1]);
                _size_map[1] = std::stoi(pString2[2]);
            }
        }
    }
    if (Running == false)
        printf("Running = false\n");
    else
        printf("Running = true\n");
}

void GuiConnect::close_socket()
{
    close(_socket);
}

void GuiConnect::close_thread()
{
    Running = false;
    printf("Je suis rentré ici");
}