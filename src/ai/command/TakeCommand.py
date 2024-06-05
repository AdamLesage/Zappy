##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## TakeCommand
##

from .CommandInterface import CommandInterface

class TakeCommand(CommandInterface):
    """Take Command"""
    def __init__(self):
        super().__init__()
        self.action = "take object"
        self.command = "Take object"
        self.time_limit = 7
        self.response = "ok/ko"
