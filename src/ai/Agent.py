##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Agent
##

class Agent():
    def __init__(self, port: int, team_name: str, ip: str = "localhost"):
        self.port = port
        self.team_name = team_name
        self.ip = ip

    def connect_to_server(self):
        """Connect to the server from the given ip and port"""
        print(f"Connecting to {self.ip} on port {self.port} with team name {self.team_name}")
        pass

    def disconnect_from_server(self):
        """Disconnect from the server"""
        pass
