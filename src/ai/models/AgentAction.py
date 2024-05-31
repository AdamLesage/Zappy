##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentAction
##

# Imports
from src.ai.models.AgentInfo import AgentInfo
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
        can_update_team_inventory = False # Check if the team inventory can be updated else return False

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
                can_update_team_inventory = True
                break

        if can_update_team_inventory == False:
            return False

        for it in self.agent_info.teamInventory:
            if it[0] == changes[0]:
                if changes[1] == "add":
                    it[1] += changes[2]
                elif changes[1] == "remove":
                    it[1] -= changes[2]
                return True
        return False

    def determineBestAction(self) -> str:
        """Determine the best action to do"""
        # Check if the agent is in incantation
        if self.agent_info.getAgentStatus() == "Incantation":
            return "Wait"
        # Check if the agent is dead
        if self.agent_info.noLifeUnits():
            return "Dead"
        # Check if the agent is in fork
        if self.agent_info.getAgentStatus() == "Fork":
            return "Fork"
        # Check if the agent has to eat
        if self.agent_info.getInventory("food") < 10:
            return "Eat"
        # Check if the agent has to incant
        if self.agent_info.getLevel() == 1:
            return "Incant"
        # Check if the agent has to get resources
        return "GetResources"