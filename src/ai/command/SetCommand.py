##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## SetCommand
##

from .CommandInterface import CommandInterface

class SetCommand(CommandInterface):
    """Set Command"""
    def __init__(self):
        super().__init__()
        self.action = "set object"
        self.command = "Set object"
        self.time_limit = 7
        self.response = "ok/ko"
