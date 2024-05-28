##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## ForwardCommand
##

from .CommandInterface import CommandInterface

class ForwardCommand(CommandInterface):
    """Forward Command"""
    def __init__(self):
        super().__init__()
        self.action = "move up one tile"
        self.command = "Forward"
        self.time_limit = 7
        self.response = "ok"

    def execute(self):
        """Execute the command"""
        pass # TODO: Implement this method