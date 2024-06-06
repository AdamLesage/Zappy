/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui_connect
*/

#include "GuiConnect.hpp"
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
    _commandFactory = std::make_shared<Zappy::CommandFactory>(0);
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
    _commandFactory = std::make_shared<Zappy::CommandFactory>(_socket);
}

void GuiConnect::send(std::string message)
{
    if (write(_socket, message.c_str(), message.size()) == -1) {
        throw Zappy::ConnectError("Failed to send message", "GuiConnect");
    }
}

void GuiConnect::receive()
{
    char buffer[10000] = {0};

    while (Running) {
        if (read(_socket, buffer, 10000) == -1) {
            throw Zappy::ConnectError("Failed to receive message", "GuiConnect");
        }
        printf("Received: [%s]\n", buffer);
        std::vector<std::string> pString = my_str_to_line_array(buffer);
        for (size_t i = 0; i < pString.size(); i++) {
            std::vector<std::string> args = my_str_to_word_array(pString[i].c_str());
            if (args.size() > 0) {
                executeCommandChanges(args[0], pString[i]);
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
}


Zappy::Inventory GuiConnect::fill_inventory(std::vector<std::string> args)
{
    Zappy::Inventory inventory;

    inventory._x = std::stoi(args[1]);
    inventory._y = std::stoi(args[2]);
    inventory._food = std::stoi(args[3]);
    inventory._linemate = std::stoi(args[4]);
    inventory._deraumere = std::stoi(args[5]);
    inventory._sibur = std::stoi(args[6]);
    inventory._mendiane = std::stoi(args[7]);
    inventory._phiras = std::stoi(args[8]);
    inventory._thystame = std::stoi(args[9]);
    return inventory;
}

void GuiConnect::executeCommandChanges(std::string commandName, std::string message)
{
    if (_commandFactory->isARegisteredCommand(commandName)) {
        std::vector<std::string> response = _commandFactory->executeCommand(commandName, message);
        if (response.size() > 0) {
            if (response[0] == "msz") {
                std::array<int, 2> size_map = {std::stoi(response[1]), std::stoi(response[2])};
                set_size_map(size_map);
            }
            if (response[0] == "pnw") {
                // Need to create a new player
            }
            if (response[0] == "bct") {
                _inventories.push_back(fill_inventory(response));
            }
        }
    }
}
