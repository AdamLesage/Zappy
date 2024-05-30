##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentInfo
##

from collections import deque

class AgentInfo():
    """AgentInfo class for the Zappy project"""
    def __init__(self):
        """Ctor of the AgentInfo class"""
        self.commandsToSend = deque(maxlen=10)
        self.commandsReturned = deque(maxlen=10)
        self.inventory = [["food", 0], ["linemate", 0], ["deraumere", 0],
                        ["sibur", 0], ["mendiane", 0], ["phiras", 0], ["thystame", 0]]
        self.client_num = 0
        self.world_width = 0
        self.world_height = 0

    # Getters
    def getCommandsToSend(self) -> list:
        """Get the list of commands to send to the server"""
        return (self.commandsToSend)

    def getCommandsReturned(self) -> list:
        """Get the list of answer send by the server"""
        return (self.commandsReturned)

    def getInventory(self, type: str) -> list:
        """
        Return an element of the inventory.
        Pass 'all' to get the whole inventory.
        """
        if type == "all":
            return self.inventory
        for it in self.inventory:
            if it[0] == type:
                return it[1]

    # Setters
    def addCommandsToSend(self, commandName: str) -> None:
        self.commandsToSend.append(commandName)

    def addCommandsReturned(self, commandName: str) -> None:
        self.commandsReturned.append(commandName)

    def addInventory(self, type: str, quantity : int) -> None:
        for it in self.inventory:
            if it[0] == type:
                it[1] += quantity
        return
