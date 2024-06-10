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

    def execute(self, client: socket, data: str = "") -> str:
        """Execute the command"""
        toSend = f"{self.command} {data}\n" if data != "" else f"{self.command}\n"
        client.send(self.command.encode())
        return toSend
