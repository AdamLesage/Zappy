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

        if changes[0] not in ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]:
            print("Invalid item", file=sys.stderr)
            return False
        if changes[1] not in ["add", "remove"]:
            print("Invalid action", file=sys.stderr)
            return False

        for it in self.agent_info.inventory:
            if it[0] == changes[0]:
                if changes[1] == "add":
                    it[1] += changes[2]
                elif changes[1] == "remove":
                    it[1] -= changes[2]
                break

        for it in self.agent_info.teamInventory:
            if it[0] == changes[0]:
                if changes[1] == "add":
                    it[1] += changes[2]
                elif changes[1] == "remove":
                    it[1] -= changes[2]
                break
        return True

    def determineBestAction(self) -> str:
        """Determine the best action to do"""
        pass