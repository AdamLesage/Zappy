##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## BroadcastCommand
##

from .CommandInterface import CommandInterface

class BroadcastCommand(CommandInterface):
    """Broadcast Command"""
    def __init__(self):
        super().__init__()
        self.action = "broadcast text"
        self.command = "Broadcast text"
        self.time_limit = 7
        self.response = "ok"

    def execute(self):
        """Execute the command"""
        pass # TODO: Implement this method
