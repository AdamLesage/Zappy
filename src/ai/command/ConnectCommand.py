##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## ConnectCommand
##

from .CommandInterface import CommandInterface

class ConnectCommand(CommandInterface):
    """Connect Command"""
    def __init__(self):
        super().__init__()
        self.action = "number of team unused slots"
        self.command = "Connect_nbr"
        self.time_limit = 0
        self.response = "value"

    def execute(self):
        """Execute the command"""
        pass # TODO: Implement this method
