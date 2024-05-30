##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## RightCommand
##

from .CommandInterface import CommandInterface

class RightCommand(CommandInterface):
    """Right Command"""
    def __init__(self):
        super().__init__()
        self.action = "turn 90° right"
        self.command = "Right"
        self.time_limit = 7
        self.response = "ok"
