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
        void close_thread();

    protected:
        int _socket;
        int _port;
        bool Running;
    private:
};

#endif /* !GUI_CONNECT_HPP_ */
