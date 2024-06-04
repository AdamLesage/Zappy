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

# Import all the commands
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

        self.availableCommands = {"connect_nbr\n": ConnectCommand(), "forward\n": ForwardCommand(),
                                "right\n": RightCommand(), "left\n": LeftCommand(),
                                "look\n": LookCommand(), "inventory\n": InventoryCommand(),
                                "broadcast\n": BroadcastCommand(), "fork\n": ForkCommand(),
                                "eject\n": EjectCommand(), "take\n": TakeCommand(), "set\n": SetCommand(),
                                "incantation\n": IncantationCommand()}
        pass

    def updateAgentInfo(self, info: AgentInfo):
        self.agentInfo = info

    def play(self, agentInfo: AgentInfo, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        Return the current state of the game: Continue, End, Dead, Incantation
        """
        alerts = self.alerts.checkAlerts()

        for alert in alerts:
            if alert.startswith("incantation"):
                self.addCommandToExecuteInList(f"Broadcast {alert}\n")
                return "Incantation"
            if alert == "food":
                return "Continue"
        return "Continue"

    def send_to_server(self) -> None:
        """Send a message to the server"""
        if self.agentInfo.commandsToSend == deque([]) or self.client == None: # If there are no commands to send, get out of the function
            return
        command_to_send = self.agentInfo.commandsToSend.popleft() # Get the first command to send and remove it from the list
        self.client.send(command_to_send.encode())
        # Add first command from waiting list to the commandsToSend list
        if self.agentInfo.commandWaitingList != []:
            self.agentInfo.commandsToSend.append(self.agentInfo.commandWaitingList.pop(0))

    def addCommandToExecuteInList(self, command: str) -> None:
        """Execute a command"""
        splited_command = command.split(' ') # Split the command to get the command and the additional data Ex: "Broadcast message\n" -> ["Broadcast", "message\n"]
        additional_data = splited_command[1] if len(splited_command) > 1 else ""
        command_idx = splited_command[0] if len(splited_command) > 1 else command
        if command_idx.find('\n') != -1:
            command = command_idx[0:len(command_idx) - 1] + '\n'
        if command_idx not in self.availableCommands:
            return
        self.availableCommands[command_idx].execute(self.client, additional_data)
        if len(self.agentInfo.commandsToSend) < 10:
            self.agentInfo.addCommandsToSend(command) # Add the command to the list of commands to send
        else:
            self.agentInfo.commandWaitingList.append(command)
