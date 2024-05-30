##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentInfo
##

from command.BroadcastCommand import BroadcastCommand
from command.ConnectCommand import ConnectCommand
from command.ForkCommand import ForkCommand
from command.ForwardCommand import ForwardCommand
from command.IncantationCommand import IncantationCommand
from command.InventoryCommand import InventoryCommand
from command.LeftCommand import LeftCommand
from command.LookCommand import LookCommand
from command.RightCommand import RightCommand
from command.SetCommand import SetCommand
from command.TakeCommand import TakeCommand
from command.EjectCommand import EjectCommand

class AgentInfo():
    """AgentInfo class for the Zappy project"""
    def __init__(self):
        """Ctor of the AgentInfo class"""
        self.commandsToSend = []
        self.commandsReturned = []
        self.inventory = [["food", 0], ["linemate", 0], ["deraumere", 0],
                        ["sibur", 0], ["mendiane", 0], ["phiras", 0], ["thystame", 0]]
        self.availableCommands = {"connect_nbr": ConnectCommand(), "forward": ForwardCommand(),
                                "right": RightCommand(), "left": LeftCommand(),
                                "look": LookCommand(), "inventory": InventoryCommand(),
                                "broadcast": BroadcastCommand(), "fork": ForkCommand(),
                                "eject": EjectCommand(), "take": TakeCommand(), "set": SetCommand(),
                                "incantation": IncantationCommand()}
        return
    
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
    def addCommandsToSend(self) -> None:
        return
    
    def addCommandsReturned(self) -> None:
        return
    
    def addInventory(self, type: str, quantity : int) -> None:
        for it in self.inventory:
            if it[0] == type:
                it[1] += quantity
        return
