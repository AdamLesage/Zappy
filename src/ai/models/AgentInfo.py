##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentInfo
##

class AgentInfo():
    """AgentInfo class for the Zappy project"""
    def __init__(self):
        """Ctor of the AgentInfo class"""
        self.commandsToSend = []
        self.commandsReturned = []
        self.inventory = [["food", 0], ["linemate", 0], ["deraumere", 0],
                        ["sibur", 0], ["mendiane", 0], ["phiras", 0], ["thystame", 0]]
        return
    
    # Getters
    def getCommandsToSend(self):
        """Get the list of commands to send to the server"""
        return (self.commandsToSend)
    
    def getCommandsReturned(self):
        """Get the list of answer send by the server"""
        return (self.commandsReturned)

    def getInventory(self, type: str):
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
    def addCommandsToSend(self):
        return
    
    def addCommandsReturned(self):
        return
    
    def addInventory(self, type: str, quantity : int):
        for it in self.inventory:
            if it[0] == type:
                it[1] += quantity
        return
