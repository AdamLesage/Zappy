##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## LeftCommand
##

from .CommandInterface import CommandInterface

class LeftCommand(CommandInterface):
    """Left Command"""
    def __init__(self):
        super().__init__()
        self.action = "turn 90° left"
        self.command = "Left"
        self.time_limit = 7
        self.response = "ok"
