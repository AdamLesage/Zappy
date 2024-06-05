/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui_connect
*/

#include <iostream>
#include <array>

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
        std::array<int, 2> get_size_map() { return _size_map; }
        void set_size_map(std::array<int, 2> size_map) { _size_map = size_map; }

    protected:
        int _socket;
        std::array<int, 2> _size_map;
        int _port;
        bool Running = true;
    private:
};

#endif /* !GUI_CONNECT_HPP_ */
