/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui_connect
*/

#include <iostream>

#ifndef GUI_CONNECT_HPP_
#define GUI_CONNECT_HPP_

class GuiConnect {
    public:
        GuiConnect();
        GuiConnect(std::string port, std::string machine);
        ~GuiConnect() = default;
        void send(std::string message);
        void receive();
        void close_socket();

    protected:
        int _socket;
        int _port;
    private:
};

#endif /* !GUI_CONNECT_HPP_ */
