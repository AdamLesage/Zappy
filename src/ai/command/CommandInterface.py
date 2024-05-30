##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## CommandInterface
##

import socket

class CommandInterface():
    """Command Interface"""
    def __init__(self) -> None:
        self.action = "This command do ..."
        self.command = "Command"
        self.time_limit = 0
        self.response = "Response"

    def execute(self, client: socket) -> str:
        """Execute the command"""
        client.send(self.command.encode())
        return self.command
