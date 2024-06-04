##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## BroadcastCommand
##

from .CommandInterface import CommandInterface

class BroadcastCommand(CommandInterface):
    """Broadcast Command"""
    def __init__(self):
        super().__init__()
        self.action = "broadcast"
        self.command = "Broadcast"
        self.time_limit = 7
        self.response = "ok"
