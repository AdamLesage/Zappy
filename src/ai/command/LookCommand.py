##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## LookCommand
##

from .CommandInterface import CommandInterface

class LookCommand(CommandInterface):
    """Look Command"""
    def __init__(self):
        super().__init__()
        self.action = "look around"
        self.command = "Look"
        self.time_limit = 7
        self.response = "[tile1, tile2, ...]"
