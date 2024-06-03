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
        self.inventory = {"food": 0, "linemate": 0, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}
        self.client_num = 0
        self.world_width = 0
        self.world_height = 0
        self.agentStatus = "Alive" # Alive, Dead, Incantation, Fork
        self.level = 1
        self.numberingVision = 1
        self.teamInventory = {"food": 0, "linemate": 0, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0} # Inventory of the team
        self.playerVision = [] # Vision of player, tiles around him
        self.lifeUnits = 1260
        self.teamPlayers = {"level1": 0, "level2": 0, "level3": 0, "level4": 0, "level5": 0, "level6": 0, "level7": 0, "level8": 0}

    def noLifeUnits(self) -> bool:
        """Return True if there is no more life units"""
        return (self.lifeUnits <= 0)

    # Getters
    def getLifeUnits(self) -> int:
        """Returns the number of life units"""
        return (self.lifeUnits)
    
    def getNumberingVision(self) -> int:
        """Get the numbering vision"""
        return (self.numberingVision)

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
        return self.inventory[type]

    def getLevel(self) -> None:
        """Get the level of the target"""
        return (self.level)

    def getPlayers(self, level: str = "all") -> int:
        """Get the number of players in the team"""
        available_levels = ["level1", "level2", "level3", "level4", "level5", "level6", "level7", "level8"]
        if level not in available_levels and level != "all":
            raise ValueError("Invalid level")
        if level != "all": # Return the number of players at the specified level
            return self.teamPlayers[level]
        return sum(self.teamPlayers.values()) # Return the sum of all players, so the total number of players in the team

    # Setters
    def setLifeUnits(self, lu: int) -> None:
        """Set the number of life Units"""
        self.lifeUnits = lu

    def setNumberingVision(self) -> None:
        """Set the numbering vision"""
        self.numberingVision += 2
    
    def addLifeUnits(self, lu: int) -> None:
        """Add the number of life Units"""
        self.lifeUnits += lu

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
        """Add a command to the list of commands to send"""
        self.commandsToSend.append(commandName)

    def addCommandsReturned(self, commandName: str) -> None:
        """Add a command to the list of commands returned by the server"""
        self.commandsReturned.append(commandName)

    def addInventory(self, type: str, quantity : int) -> None:
        """Add an item to the inventory"""
        if type not in ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]:
            raise ValueError(f"Invalid item {type}")
        self.inventory[type] += quantity

    def addPlayers(self, level: str, quantity: int) -> None:
        """Set the number of players in the team"""
        available_levels = ["level1", "level2", "level3", "level4", "level5", "level6", "level7", "level8"]
        if level not in available_levels:
            raise ValueError(f"Invalid level {level}")
        self.teamPlayers[level] += quantity
