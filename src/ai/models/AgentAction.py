##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentAction
##

# Imports
from models.AgentInfo import AgentInfo
import sys

class AgentAction():
    """AgentAction class for the Zappy project"""
    def __init__(self, agent_info: AgentInfo):
        """Ctor of the AgentAction class"""
        self.action = None
        self.agent_info = agent_info

    def updateInventories(self, changes: list[str, str, int]) -> bool:
        """Update the team inventory return True if the update was successful"""
        # Changes = [item, action, quantity]
        # item = name of the item
        # action = add, remove
        # quantity = quantity to add or remove
        item = changes[0]
        print(f"Item: [{item}], {self.agent_info.inventory}")

        if item not in self.agent_info.inventory:
            print(f"Invalid item [{item}]", file=sys.stderr)
            return False
        if changes[1] not in ["add", "remove"]:
            print(f"Invalid action [{changes[1]}]", file=sys.stderr)
            return False

        if changes[1] == "add": # Add the item to the inventory and to the team inventory
            self.agent_info.inventory[item] += changes[2]
            self.agent_info.teamInventory[item] += changes[2]
        elif changes[1] == "remove": # Remove the item from the inventory and from the team inventory
            self.agent_info.inventory[item] -= changes[2]
            self.agent_info.teamInventory[item] -= changes[2]

        return True

    def useAlerts(self, alerts: list[str]) -> None:
        """
        Use alerts
        """
        for alert in alerts:
            if alert == "food":
                self.agent.findFood()
            # if alert == "incantation":
            #     self.agent.findIncantation()

    def findFood(self) -> None:
        """Find food"""
        self.agent_info.addCommandsToSend("look\n")