##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## EjectCommand
##

from .CommandInterface import CommandInterface

class EjectCommand(CommandInterface):
    """Eject Command"""
    def __init__(self):
        super().__init__()
        self.action = "eject players from this tile"
        self.command = "Eject"
        self.time_limit = 7
        self.response = "ok/ko"
