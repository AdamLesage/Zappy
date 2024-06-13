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
std::vector<std::string> split(std::string str, std::string separator);
std::vector<std::string> my_str_to_word_array_separator(const char *str, char separator);

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

void GuiConnect::readServer(std::string &buffer2, char *buffer)
{
    std::vector<std::string> pString;

    for (int j = 0; j <= client_management.max_fd; j++) {
        if (FD_ISSET(j, &client_management.temp_fds)) {
            for (int c = 0; c != 100000; c++)
                buffer[c] = '\0';
            if (read(_socket, buffer, 100000) == -1) {
                throw Zappy::ConnectError("Failed to receive message", "GuiConnect");
            }
            if (buffer2.empty()) {
                buffer2 = buffer;
            } else {
                buffer2 += buffer;
            }
            if (buffer2.find('\n') == buffer2.npos) {
                break;
            }
            pString = split(buffer2, "\n");
            for (size_t i = 0; i < pString.size(); i++) {
                std::vector<std::string> args = my_str_to_word_array(pString[i].c_str());
                if (args.size() > 0) {
                    executeCommandChanges(args[0], pString[i]);
                    buffer2 = "";
                }
            }
            pString.clear();
        }
    }
}

void GuiConnect::receive()
{
    char buffer[100000] = {0};
    std::string buffer2;
    FD_ZERO(&(client_management.rfds));
    FD_SET(_socket, &client_management.rfds);
    int retval = 0;

    client_management.max_fd = _socket;
    if (read(_socket, buffer, 100000) == -1) {
        throw Zappy::ConnectError("Failed to receive message", "GuiConnect");
    }
    send("GRAPHIC\n");
    while (Running) {
        client_management.temp_fds = client_management.rfds;
        retval = select(client_management.max_fd + 1, &client_management.temp_fds, NULL, NULL, NULL);
        if (retval == -1) {
            throw Zappy::ConnectError("Select error", "GuiConnect");
        }
        if (retval >= 0) {
            readServer(buffer2, buffer);
        }
    }
}

void GuiConnect::close_socket()
{
    close(_socket);
}

void GuiConnect::close_thread()
{
    Running = false;
}


void GuiConnect::executeCommandChanges(std::string commandName, std::string message)
{
    if (_commandFactory->isARegisteredCommand(commandName)) {
        _commandFactory->executeCommand(commandName, message, _size_map, _tiles, _players, _eggs, _teams, _timeUnit, Running);
    }
}
