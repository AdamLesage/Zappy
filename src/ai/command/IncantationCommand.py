##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## IncantationCommand
##

from .CommandInterface import CommandInterface

class IncantationCommand(CommandInterface):
    """Incantation Command"""
    def __init__(self):
        super().__init__()
        self.action = "start incantation"
        self.command = "Incantation"
        self.time_limit = 300
        self.response = "Elevation underway Current level: k/ko"
