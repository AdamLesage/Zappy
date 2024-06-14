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
        self.commandsToSend = deque(maxlen=10) # Defined as a deque with a max length of 8 because we need to execute Look and Inventory commands every 8 rounds
        #self.commandsReturned = deque(maxlen=8)
        self.commandsReturned = [None, None]
        self.commandWaitingList = []
        self.inventory = {"food": 0, "linemate": 0, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}
        self.client_num = 0
        self.world_width = 0
        self.world_height = 0
        self.movements = []
        self.agentStatus = "Alive" # Alive, Dead, Incantation, Fork
        self.level = 1
        self.numberingVision = 1
        self.teamInventory = {"food": 0, "linemate": 0, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0} # Inventory of the team
        self.playerVision = [] # Vision of player, tiles around him
        self.lifeUnits = 10
        self.timeUnits = 1260
        self.broadcast_received = None
        self.numberMaxOfTeamPlayers = 0
        self.numberOfTeamPlayersConnected = 0
        self.availableSlots = 0
        self.broadcast_received = None
        self.broadcast_orientation = None
        self.incantationResponses = 0
        self.numberToEvolve = {"level2": 1, "level3": 2, "level4": 2, "level5": 4, "level6": 4, "level7": 6, "level8": 6} # Number of players needed to evolve to the next level

    def noLifeUnits(self) -> bool:
        """Return True if there is no more life units"""
        return (self.lifeUnits <= 0)

    def noTimeUnits(self) -> bool:
        """Return True if there is no more time units"""
        return (self.timeUnits <= 0)

    def manageBroadcastReceived(self) -> None:
        """Do something with the broadcast received"""
        if self.broadcast_received != None and self.broadcast_received.startswith("message"):
            incantation_orientation = self.broadcast_received.split(" ")[1].replace(",", "")
            incantation_message = self.broadcast_received.split(" ")[2]
            self.broadcast_received = None

    # Getters
    def getTimeUnits(self) -> int:
        """Returns the number of time units"""
        return (self.timeUnits) 

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

    # Setters  
    def setTimeUnits(self, tu: int) -> None:
        """Set the number of time Units"""
        self.timeUnits = tu
    
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
        self.inventory[type] = int(quantity)
