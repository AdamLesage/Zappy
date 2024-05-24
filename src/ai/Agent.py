##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Agent
##

import socket

class Agent():
    def __init__(self, port: int, team_name: str, ip: str = "localhost"):
        self.port = port
        self.team_name = team_name
        self.ip = ip
        self.client = None

    def connect_to_server(self) -> None:
        """Connect to the server from the given ip and port"""
        try:
            self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client.connect((self.ip, self.port))
            while True:
                data = self.client.recv(1024).decode()
                print(f"Received: {data}")


        except Exception as e:
            print(f"Error: {e}")
            exit(84)



    def disconnect_from_server(self) -> None:
        """Disconnect from the server"""
        pass
