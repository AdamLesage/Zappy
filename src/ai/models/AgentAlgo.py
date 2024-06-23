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
from models.AgentBroadcast import AgentBroadcast
import os

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

# Import functions
from models.agent_gameplay import AgentGameplayMixin
from models.agent_incantation import AgentIncantationMixin
from models.agent_reproduction import AgentReproductionMixin

# Import libraries
import random
from collections import deque
import socket

class AgentAlgo(AgentGameplayMixin, AgentIncantationMixin, AgentReproductionMixin):
    """
    This class is the main class for the agent's algorithm.
    It will handle the agent's actions and decisions.
    """
    def __init__(self, agentInfo: AgentInfo, fTime: int,
            client: socket = None, ip: str = "0.0.0.0", port: int = 4242, teamName: str = "team"):
        self.alerts = AgentAlerts(agentInfo, fTime)
        self.agentInfo = agentInfo
        self.agentMoves = Moves()
        self.agentBroadcast = AgentBroadcast()
        self.client = client
        self.ip = ip
        self.port = port
        self.teamName = teamName
        self.status = "Mining" # Mining, Food, Incantation, Ask incantation, Going to incantation, Waiting player to start incantation, Preparing incantation
        self.hasAskedIncantation = False
        self.hasAcceptedIncantation = False
        self.availableCommands = {"connect_nbr\n": ConnectCommand(), "forward\n": ForwardCommand(),
                                "right\n": RightCommand(), "left\n": LeftCommand(),
                                "look\n": LookCommand(), "inventory\n": InventoryCommand(),
                                "broadcast\n": BroadcastCommand(), "fork\n": ForkCommand(),
                                "eject\n": EjectCommand(), "take\n": TakeCommand(), "set\n": SetCommand(),
                                "incantation\n": IncantationCommand()}
        self.playerOnSameTileForIncantation = 1
        self.isWaitingForResponses = False
        self.hasAskedPlayerConnected = False
        self.isPlayerConnected = False
        self.borntick = 0
        self.alReadyResponded = False
        self.broadcastReceived = None # Broadcast received from the server
        self.broadcastPassed = 0 # Number of broadcast passed to avoid waiting incantation until death
        self.canStartCounting = False
        self.countPassedCommands = 0

    def updateFoodMode(self) -> None:
        if self.status == "Going to incantation" or self.status == "Preparing incantation" or self.status == "Incantation":
            return
        try:
            if len(self.alerts.checkAlerts()) == 0:
                return False
            alert = self.alerts.checkAlerts().pop()
            if alert == "food":
                self.status = "Food"
                return True
            return False
        except Exception as e:
            print(f"Error from updateClientStatus: {e}")

    def updateClientStatus(self) -> None:
        """
        Update the client status.
        State could be: Continue, End, Dead, Incantation, Food
        """
        if self.status == "Going to incantation" or self.status == "Preparing incantation" or self.status == "Incantation":
            return
        try:
            if len(self.alerts.checkAlerts()) == 0:
                return
            alert = self.alerts.checkAlerts().pop()
            print(f"Alert: {alert}")
            if alert == "food":
                self.status = "Food"
                return
            if alert.startswith("incantationNeeded"):
                self.agentInfo.commandsToSend.clear()
                self.status = "Ask incantation" # Do not change status to incantation, need to wait for other agents except if player is level 1 
                return
            self.status = "Mining"
        except Exception as e:
            print(f"Error from updateClientStatus: {e}")

    def foodMode(self) -> None:
        """
        The agent is in food mode, it will search for food
        """
        actions = ["Forward\n", "Right\n", "Forward\n", "Left\n"] # More chance to go forward (x2)
        if self.agentInfo.getInventory("food") > 20:
            if self.hasAcceptedIncantation == False:
                self.status = "Mining"
            else:
                self.status = "Going to incantation"
            return
        buf = self.getReturnCommand()[1]
        self.agentInfo.checkPlayerLevelFromLook(buf)
        if self.status != "Food":
            return
        if self.agentMoves.checkItem(self.getReturnCommand()[1], "food"):
            self.agentInfo.movements = self.agentMoves.reachItemList("food", buf)
            return
        else:
            finalAction = random.choice(actions)
            self.agentInfo.addCommandsToSend(finalAction)
            return

    def miningMode(self) -> None:
        """
        The agent is in mining mode, it will search for resources
        """
        if self.status == "Going to incantation" or self.status == "Preparing incantation" or self.status == "Incantation":
            return
        if self.agentInfo.commandsToSend.count("Look\n") < 2:
            self.agentInfo.commandsToSend.append("Look\n")
        actions = ["Forward\n", "Right\n", "Left\n"] # More chance to go forward (x2)
        buf = self.getReturnCommand()[1]
        self.agentInfo.checkPlayerLevelFromLook(buf)
        if buf != None and self.agentMoves.checkItems(buf, ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]) != []: # If there are resources to take
            availables_resources = self.agentMoves.checkItems(buf, ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"])
            item = self.agentMoves.findBestItemToTake(self.agentInfo, self.agentInfo.getLevel(), availables_resources)
            self.agentInfo.movements = self.agentMoves.reachItemList(item, buf)
            return
        else:
            finalAction = random.choice(actions)
            self.agentInfo.addCommandsToSend(finalAction)
            return


    def inventoryManagement(self) -> bool:
        """
        Check the inventory of the agent:
        - Send the command "Inventory" to the server.
        - Update the inventory of the agent.
        """
        try:
            command_output = self.getReturnCommand()
            
            if command_output[0] == "Inventory\n":
                if command_output[1] == None or command_output[1].startswith("[") == False:
                    return False
                self.agentInfo.updateInventory(command_output[1])
                return False

            if self.countPassedCommands % 30 == 0 and self.status != "Incantation" and not f"Inventory\n" in self.agentInfo.commandsToSend: # Frequency of inventory check, avoid to check inventory if incantation is in progress
                self.agentInfo.commandsToSend.append("Inventory\n")
                return True

            return False
        except ValueError as e:
            print(f"Error from inventoryManagement: {e}")
            return False


    def play(self) -> None:
        """
        Play the game, search for resources, level up, incantation, etc
        """
        try:
            if self.status == "Incantation" or self.status == "is waiting player to start incantation":
                return
            if self.inventoryManagement():
                return
            if self.agentBroadcast.goToBroadcast(self.agentInfo.broadcast_orientation, self.agentInfo, self.status) == True:
                if self.agentInfo.posIs0 == True:
                    self.status = "is waiting player to start incantation"
                    print(f"Player status: {self.status}")
                    self.agentInfo.commandsToSend.append("Broadcast I_m_here\n")
                    self.agentInfo.broadcast_orientation = None
                return
            else:
                self.agentInfo.broadcast_orientation = None # Reset the broadcast orientation
            if self.status != "Can start incantation":
                self.updateClientStatus()
            if self.getReturnCommand()[0] == "Look\n" and self.status == "Food":
                self.foodMode()
                return
            if self.status == "Waiting player to start incantation":
                self.clientPlayLevel1()
                self.clientPlayLevel2()
                self.clientPlayLevel3()
                self.clientPlayLevel4()
                self.clientPlayLevel5()
                self.clientPlayLevel6()
                self.clientPlayLevel7()
                self.clientPlayLevel8()
                return
            # self.borntick += 1
            if self.agentInfo.movements != []:
                self.agentInfo.addCommandsToSend(self.agentInfo.movements.pop(0))
                return
            self.incantationManagement()
            if self.status == "Food":
                if self.agentInfo.commandsToSend.count("Look\n") < 2:
                    self.agentInfo.commandsToSend.append("Look\n")
                return
            if self.status == "Preparing incantation":
                self.launchIncantation()
                if self.agentInfo.getLevel() == 2:
                    exit(0)
                return
            self.clientPlayLevel1()
            self.clientPlayLevel2()
            self.clientPlayLevel3()
            self.clientPlayLevel4()
            self.clientPlayLevel5()
            self.clientPlayLevel6()
            self.clientPlayLevel7()
            self.clientPlayLevel8()
        except Exception as e:
            print(f"Error from play: {e}")
            return

    def send_to_server(self) -> None:
        """Send a message to the server"""
        if self.agentInfo.commandsReturned[0] != None:
            self.clearReturnCommand()
        if self.agentInfo.commandsToSend == deque([]) or self.client == None: # If there are no commands to send, get out of the function
            return
        command_to_send = self.agentInfo.commandsToSend.popleft()
        self.client.send(command_to_send.encode())
        self.agentInfo.commandsReturned = [command_to_send, None]
        self.countPassedCommands += 1


    def setReturnCommandAnswer(self, serverAnswer: str) -> None:
        """Set the command to return"""
        self.agentInfo.commandsReturned[1] = serverAnswer
    
    def getReturnCommand(self) -> list:
        """Get the command to return"""
        return self.agentInfo.commandsReturned
    
    def clearReturnCommand(self) -> None:
        """Clear the command to return"""
        self.agentInfo.commandsReturned = [None, None]


    def broadcastManagement(self, data: str) -> bool:
        """
        Manage the broadcast
        Split data with ' ' ---> ["message", "K,", "text"]
        Agent can accept the incantation but need to broadcast answer
        """
        #if self.status == "Going to incantation":
        if data == None or "message" not in data:
            return False
        if self.status == "Food":
            return False
        if "empty" in data:
            self.agentInfo.broadcast_received = "empty"
            return False
        if "Incantation_finished" in data:
            self.status = "Food"
            self.hasAcceptedIncantation = False
            self.hasAskedIncantation = False
            self.isWaitingForResponses = False
            self.playerOnSameTileForIncantation = 1
            self.agentInfo.incantationResponses = 0
            self.agentInfo.broadcast_received = None
            self.agentInfo.broadcast_orientation = None
            self.agentInfo.posIs0 = False
            return False
        if "I_m_here" in data:
            self.status = "Can start incantation"
            return False
        self.broadcastReceived = data
        data = data.replace(",", "") # remove comma after K
        data = data.replace("\n", "") # remove \n at the end of the string
        try:
            self.agentInfo.broadcast_received = data.split(' ')[2]
            if self.agentInfo.broadcast_received != None and self.agentInfo.broadcast_received.startswith(f"need_incantation_level_{self.agentInfo.getLevel()}"):
                # Only retrieve orientation if the broadcast is waiting for incantation
                self.agentInfo.broadcast_orientation = data.split(' ')[1]
                print(f"Broadcast received: {self.agentInfo.broadcast_received} with orientation {self.agentInfo.broadcast_orientation}")

            self.agentInfo.commandsToSend.clear()
            self.acceptOrRefuseIncantation()
            self.playerOnSameTile()
            return True

            # print(f"Command to send {self.agentInfo.commandsToSend[-1]}")
        except Exception as e:
            print(f"Error from broadcast management: {e} from data: {data}")
            return False
