##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## InventoryCommand
##

from .CommandInterface import CommandInterface

class InventoryCommand(CommandInterface):
    """Inventory Command"""
    def __init__(self):
        super().__init__()
        self.action = "inventory"
        self.command = "Inventory"
        self.time_limit = 1
        self.response = "[linemate n, sibur n, ...]"

    def execute(self):
        """Execute the command"""
        pass # TODO: Implement this method