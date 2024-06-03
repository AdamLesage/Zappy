##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentAlgo
##

# Imports
from models.AgentAlert import AgentAlerts
from models.AgentInfo import AgentInfo
from models.AgentMoves import Moves

# Import libraries
from collections import deque
import socket

class AgentAlgo():
    """
    This class is the main class for the agent's algorithm.
    It will handle the agent's actions and decisions.
    """
    def __init__(self, agentInfo: AgentInfo, fTime: int, client: socket = None):
        self.alerts = AgentAlerts(agentInfo, fTime)
        self.agentInfo = agentInfo
        self.agentMoves = Moves()
        self.client = client
        pass

    def updateAgentInfo(self, info: AgentInfo):
        self.agentInfo = info

    def play(self, agentInfo: AgentInfo, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        Return the current state of the game: Continue, End, Dead, Incantation
        """
        alerts = self.alerts.checkAlerts()

        if "incantation" in alerts:
            # setup the logic for incantation
            return "Incantation"
        if "food" in alerts:
            #
            return "Continue"
        return "Continue"

    def send_to_server(self) -> None:
        """Send a message to the server"""
        if self.agentInfo.commandsToSend == deque([]) or self.client == None: # If there are no commands to send, get out of the function
            return
        command_to_send = self.agentInfo.commandsToSend.popleft() # Get the first command to send and remove it from the list
        print(f"{self.agentInfo.commandsToSend=} <--------")
        self.client.send(command_to_send.encode())
