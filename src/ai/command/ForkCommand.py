##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## *
##

from .CommandInterface import CommandInterface

class ForkCommand(CommandInterface):
    """Fork Command"""
    def __init__(self):
        super().__init__()
        self.action = "fork a player"
        self.command = "Fork"
        self.time_limit = 42
        self.response = "ok"

    def execute(self):
        """Execute the command"""
        pass # TODO: Implement this method
