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
        self.agentStatus = "Alive" # Alive, Dead, Incantation, Fork
        self.level = 1

    # Getters
    def getAgentStatus(self) -> str:
        """Get the status of the agent: Alive, Dead, Incantation, Fork"""
        return (self.agentStatus)
    
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
    
    def getLevel(self) -> None:
        """Get the level of the target"""
        return (self.level)

    # Setters
    def setLevel(self, level: int) -> None:
        """Set the level of the target"""
        if level > 8 or level < 1:
            raise ValueError("Invalid level")
        self.level = level
    
    def setStatus(self, status: str) -> None:
        """Set the status of the agent: Alive, Dead, Incantation, Fork"""
        if status not in ["Alive", "Dead", "Incantation", "Fork"]:
            raise ValueError("Invalid status")
        self.agentStatus = status
    
    def addCommandsToSend(self, commandName: str) -> None:
        self.commandsToSend.append(commandName)

    def addCommandsReturned(self, commandName: str) -> None:
        self.commandsReturned.append(commandName)

    def addInventory(self, type: str, quantity : int) -> None:
        for it in self.inventory:
            if it[0] == type:
                it[1] += quantity
        return
