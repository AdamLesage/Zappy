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
        self.round = 0
        self.agentMentality = "None" #Hungry, Incantation, Mining, None

        self.availableCommands = {"connect_nbr\n": ConnectCommand(), "forward\n": ForwardCommand(),
                                "right\n": RightCommand(), "left\n": LeftCommand(),
                                "look\n": LookCommand(), "inventory\n": InventoryCommand(),
                                "broadcast\n": BroadcastCommand(), "fork\n": ForkCommand(),
                                "eject\n": EjectCommand(), "take\n": TakeCommand(), "set\n": SetCommand(),
                                "incantation\n": IncantationCommand()}
        pass

    def updateAgentInfo(self, info: AgentInfo):
        self.agentInfo = info
    
    #def defineFoodAlert(self, agentInfo: AgentInfo) -> None:
    #    """
    #    It will define the alert threshold for food,
    #    based on the player's level.
    #    It's updated every 10 rounds.
    #    """
    #    if self.round % 10 != 0:
    #        return
    #    agentInfo.commandsToSend.insert(0, "Inventory")
    #    agentInfo.commandsToSend.insert(1, "Look")
    #    return

    def updateInventory(self, inv: str) -> None:
        """
        Update the inventory of the agent
        """
        inv = inv.replace("[", "")
        inv = inv.replace("]", "")
        for idx, char in enumerate(inv):
            if char == "," and inv[idx + 1] == " ":
                inv = inv.replace(", ", ",")
        splitedInf = inv.split(',')
        for item in splitedInf:
            item = item.split(' ')
            if self.agentInfo.inventory[item[0]] == int(item[1]):
                continue
            self.agentInfo.addInventory(item[0], item[1])
        return

    def play(self, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        """
        alerts = self.alerts.checkAlerts()

        if self.getReturnCommand()[0] == "Inventory\n":
            self.updateInventory(self.getReturnCommand()[1])
            for item, qt in self.agentInfo.inventory.items():
                print(f"{item}: {qt}")
            return
        if self.round % 2 == 0:
            print("list of commands to send: ", self.agentInfo.commandsToSend)
            self.agentInfo.commandsToSend.insert(0, "Inventory\n")
            self.round += 1
            return
        if self.agentMentality == "Incantation":
            return
        if self.agentMentality == "Hungry":
            return None
        for alert in alerts:
            if alerts == []:
                break
            if alert == "food":
                self.agentMentality = "Hungry"
                self.agentInfo.commandsToSend.clear()
                self.agentInfo.addCommandsToSend("Look")
                return
            if alert.startswith("incantation"):
                self.addCommandToExecuteInList(f"Broadcast {alert}\n")
                self.agentMentality = "Incantation"
                return
        self.round += 1
        return

    def send_to_server(self) -> None:
        """Send a message to the server"""
        if self.agentInfo.commandsReturned[0] != None:
            return None
        if self.agentInfo.commandsToSend == deque([]) or self.client == None: # If there are no commands to send, get out of the function
            return None
        command_to_send = self.agentInfo.commandsToSend.popleft()
        print(f"Sending command: {command_to_send}")
        self.client.send(command_to_send.encode())
        tmp = [command_to_send, ""]
        self.agentInfo.commandsReturned = tmp
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
    
    #def receiveFromServer(self) -> str:
    #    """Receive a message from the server"""
    #    self.client.setblocking(0)
    #    try:
    #        receivedData = self.client.recv(1024).decode()
    #    except BlockingIOError:
    #        return None
    #    return receivedData

    def setReturnCommandAnswer(self, serverAnswer: str) -> None:
        """Set the command to return"""
        self.agentInfo.commandsReturned[1] = serverAnswer
    
    def getReturnCommand(self) -> str:
        """Get the command to return"""
        return self.agentInfo.commandsReturned
    
    def clearReturnCommand(self) -> None:
        """Clear the command to return"""
        self.agentInfo.commandsReturned = [None, None]
