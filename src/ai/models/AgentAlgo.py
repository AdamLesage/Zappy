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

# Import libraries
import random
from collections import deque
import socket

class AgentAlgo():
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
        pass

    def setStatus(self, status: str) -> None:
        self.status = status

    def updateAgentInfo(self, info: AgentInfo):
        self.agentInfo = info

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

    def clientPlayLevel1(self) -> None:
        """
        If the agent is level 1, do the actions for level 1
        Actions such as: search for food, search for resources, level up, etc
        """
        if self.agentInfo.getLevel() != 1 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        if self.status == "Ask incantation":
            self.setItemsForIncantation()
        else:
            self.miningMode()
            
    def clientPlayLevel2(self) -> None:
        """
        If the agent is level 2, do the actions for level 2
        Actions such as: search for food, search for resources, level up, etc
        """
        if self.agentInfo.getLevel() != 2 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
            return
        if self.status == "Ask incantation" or self.status == "Waiting player to start incantation":
            self.hasAskedIncantation = True
            #self.agentInfo.commandsToSend.clear()
            if len(self.agentInfo.commandsToSend) >= 2:
                return
            self.status = "Waiting player to start incantation"
            self.agentInfo.commandsToSend.append(f"Broadcast need_incantation_level_{self.agentInfo.getLevel()}\n")
            self.agentInfo.commandsToSend.append(f"Broadcast empty\n")
            print(f"Broadcast need_incantation_level_{self.agentInfo.getLevel()} | client num {self.agentInfo.client_num}")
        else:
            self.miningMode()

    def clientPlayLevel3(self) -> None:
        """
        If the agent is level 3, do the actions for level 3
        Actions such as: search for food, help agent level 1 to upgrade to level 2, level up, etc
        """
        if self.agentInfo.getLevel() != 3 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode()  # Search for food
        else:
            self.miningMode()

    def clientPlayLevel4(self) -> None:
        """
        If the agent is level 4, do the actions for level 4
        Actions such as: search for food, help agent level 2 to upgrade to level 3, level up, etc
        Once level 4 is reached, agent is considered as a "helper" agent
        Then once there is enough agents to reach level 5, he will join or start an incantation to level 5
        """
        if self.agentInfo.getLevel() != 4 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel5(self) -> None:
        """
        If the agent is level 5, do the actions for level 5
        Actions such as: search for food, help agent level 3 to upgrade to level 4, level up, etc
        """
        if self.agentInfo.getLevel() != 5 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel6(self) -> None:
        """
        If the agent is level 6, do the actions for level 6
        Actions such as: search for food, help agent level 4 and level 5 to upgrade to level 6, level up, etc
        The goal of agent level 6 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 6 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel7(self) -> None:
        """
        If the agent is level 7, do the actions for level 7
        Actions such as: search for food, help agent and level 4, level 5 and level 6 to upgrade to level 7, level up, etc
        The goal of agent level 7 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 7 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel8(self) -> None:
        """
        If the agent is level 8, do the actions for level 8
        Actions such as: search for food, help agent and level 4, level 5, level 6 and level 7 to upgrade to level 8, level up, etc
        The goal of agent level 8 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 2 or self.status == "Incantation":
            return
        self.foodMode() # Search for food

    def foodMode(self) -> None:
        """
        The agent is in food mode, it will search for food
        """
        actions = ["Forward\n", "Right\n", "Forward\n", "Left\n"] # More chance to go forward (x2)
        if self.agentInfo.getInventory("food") > 15:
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

    def setItemsForIncantation(self) -> None:
        """
        Set the items to take for the incantation
        """
        # TODO: look before setting everything to avoid to take the same item twice
        print(f"Set items for incantation | level {self.agentInfo.getLevel()}")
        self.agentInfo.commandsToSend.clear()
        if self.agentInfo.getLevel() == 1:
            self.agentInfo.commandsToSend.append("Set linemate\n")
        elif self.agentInfo.getLevel() == 2:
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
        elif self.agentInfo.getLevel() == 3:
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set phiras\n")
            self.agentInfo.commandsToSend.append("Set phiras\n")
        elif self.agentInfo.getLevel() == 4:
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set phiras\n")
        elif self.agentInfo.getLevel() == 5:
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set mendiane\n")
            self.agentInfo.commandsToSend.append("Set mendiane\n")
            self.agentInfo.commandsToSend.append("Set mendiane\n")
        elif self.agentInfo.getLevel() == 6:
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set phiras\n")
        elif self.agentInfo.getLevel() == 7:
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set linemate\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set deraumere\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set sibur\n")
            self.agentInfo.commandsToSend.append("Set mendiane\n")
            self.agentInfo.commandsToSend.append("Set mendiane\n")
            self.agentInfo.commandsToSend.append("Set phiras\n")
            self.agentInfo.commandsToSend.append("Set thystame\n")
        self.status = "Preparing incantation"

    def createChild(self) -> None:
        pid = os.fork()
        if pid > 0:
            # print(f"Parent process: {os.getpid()}") # Parent process
            pass # Maybe add fork command
        else:
            pass
            # print(f"Child process: {os.getpid()}")
            #os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.teamName, "-h", self.ip])

    def launchIncantation(self) -> None:
        """
        Launch the incantation
        """
        print(f"Ask incantation | level {self.agentInfo.getLevel()}")
        if self.status != "Preparing incantation":
            return

        if self.playerOnSameTileForIncantation >= self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]: # If there is enough agent to evolve
            if self.agentInfo.getLevel() != 1:
                print(f"Enough players to evolve to level {self.agentInfo.getLevel() + 1}")
            self.setItemsForIncantation()
            self.status = "Incantation"
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.commandsToSend.append("Incantation\n")
            self.playerOnSameTileForIncantation = 1


    def incantationManagement(self) -> None:
        """
        Manage the incantation of the agent
        """
        if self.status != "Incantation" and self.status != "Ask incantation" and self.status != "Going to incantation" and self.status != "Waiting player to start incantation" and self.status != "Incantation in progress":
            # Status is not incantation
            return

        if self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("Current level:"): # If the incantation is a success
            self.hasAskedIncantation = False
            self.status = "Food"
            # level_to_set = int(self.getReturnCommand()[1].split(" ")[-1])
            # print(f"Current level [{self.getReturnCommand()[1]}] | level to set {level_to_set}")
            # self.agentInfo.setLevel(self.agentInfo.getLevel() + 1) # TODO: does not work
            if self.agentInfo.commandsToSend.count("Look\n") < 2:
                self.agentInfo.commandsToSend.append("Look\n")
            self.agentInfo.incantationResponses = 1
            self.agentInfo.commandsToSend.append("Connect_nbr\n")
            self.hasAcceptedIncantation = False

        elif self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("ko"): # If the incantation is a failure
            self.hasAskedIncantation = False
            self.hasAcceptedIncantation = False
            self.agentInfo.incantationResponses = 1
            self.status = "Food"
            # print(f"Player level {self.agentInfo.getLevel()} has failed incantation with status {self.status}")


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

            if self.countPassedCommands % 10 == 0 and self.status != "Incantation" and not f"Inventory\n" in self.agentInfo.commandsToSend: # Frequency of inventory check, avoid to check inventory if incantation is in progress
                self.agentInfo.commandsToSend.append("Inventory\n")
                return True

            return False
        except ValueError as e:
            print(f"Error from inventoryManagement: {e}")
            return False

    def checkPlayerIncantationWaiting(self) -> None:
        """
        Check if the player is waiting for incantation
        To avoid waiting for incantation until death
        """
        if self.canStartCounting == False:
            return
        self.broadcastPassed += 1
        # TODO: check why player is stuck in incantation
        if (self.broadcastPassed >= 15 and self.status == "Going to incantation"): #and self.agentInfo.incantationResponses < self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]:
            self.status = "Food"
            print(f"Player level {self.agentInfo.getLevel()} has waited for incantation too long | responses {self.agentInfo.incantationResponses} instead of {self.agentInfo.numberToEvolve[f'level{self.agentInfo.getLevel() + 1}']}")
            self.broadcastPassed = 0
            self.canStartCounting = False
            self.hasAskedIncantation = False

    def play(self, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        """
        print(f"Status: {self.status}, level {self.agentInfo.getLevel()}")
        # if self.status == "Waiting player to start incantation":
        #     return
        try:
            if self.status == "Incantation":
                return
            if self.inventoryManagement():
                return
            #print(f"Status: {self.status} | Level: {self.agentInfo.getLevel()}")
            #self.checkPlayerIncantationWaiting()
            if self.agentBroadcast.goToBroadcast(self.agentInfo.broadcast_orientation, self.agentInfo, self.status) == True:
                return
            else:
                self.agentInfo.broadcast_orientation = None # Reset the broadcast orientation
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
            #self.launchIncantation()
            # print("Inventory management done")
            # print("Food mode done")
            if self.agentInfo.movements != []:
                self.agentInfo.addCommandsToSend(self.agentInfo.movements.pop(0))
                return
            # print("Movements done")
            # print("Check inventory done")
            #if self.waitingIncantationResponses() == True:
            #    return
            #self.incantationManagement()
            if self.status == "Food":
                if self.agentInfo.commandsToSend.count("Look\n") < 2:
                    self.agentInfo.commandsToSend.append("Look\n")
                return
            if self.status == "Preparing incantation":
                self.launchIncantation()
                return
            # print("Food status done")
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
        print(f"Command to send: {command_to_send}")
        self.client.send(command_to_send.encode())
        self.agentInfo.commandsReturned = [command_to_send, None]


    def setReturnCommandAnswer(self, serverAnswer: str) -> None:
        """Set the command to return"""
        self.agentInfo.commandsReturned[1] = serverAnswer
    
    def getReturnCommand(self) -> list:
        """Get the command to return"""
        return self.agentInfo.commandsReturned
    
    def clearReturnCommand(self) -> None:
        """Clear the command to return"""
        self.agentInfo.commandsReturned = [None, None]

    def waitingForkResponseFinalStep(self) -> None:
        if self.hasAskedPlayerConnected == False:
            return
        if self.isPlayerConnected == True:
            return
        if self.agentInfo.broadcast_received == "yes_we_are_on_the_map" and self.isPlayerConnected == False:
            self.isPlayerConnected = True
            self.hasAskedPlayerConnected = True

    def waitingForkResponse(self) -> None:
        if self.hasAskedPlayerConnected == False:
            return
        if self.alReadyResponded == True:
            return
        if self.agentInfo.broadcast_received == "Anybody_on_the_map_?":
            self.agentInfo.commandsToSend.append(f"Broadcast yes_we_are_on_the_map\n")
            self.alReadyResponded = True
            self.isPlayerConnected = True
            self.hasAskedPlayerConnected = True

    def AnybodyHere(self) -> None:
        """
        Check if there are any other players on the map
        """
        if self.hasAskedPlayerConnected == True:
            return
        if self.isPlayerConnected == True:
            return
        self.agentInfo.commandsToSend.append(f"Broadcast Anybody_on_the_map_?\n")
        self.hasAskedPlayerConnected = True

    def AnybodyHere(self) -> None:
        """
        Check if there are any other players on the map
        """
        if self.hasAskedPlayerConnected == True:
            return
        if self.isPlayerConnected == True:
            return
        self.agentInfo.commandsToSend.append(f"Broadcast Anybody_on_the_map_?\n")
        print(f"Broadcast Anybody_on_the_map_?")
        self.hasAskedPlayerConnected = True

    def ConnectNbrManagement(self) -> None:
        """
        Manage the Connect_nbr command
        Create a fork if there is no available slots
        """
        if self.agentInfo.commandsReturned[0] != "Connect_nbr\n":
            # There is no Connect_nbr command to manage or response has not been received
            return
        if self.agentInfo.commandsReturned[1] == None:
            # If the response has not been received
            return
        number_received = self.agentInfo.commandsReturned[1].replace("\n", "")
        if number_received.isdigit() == False:
            # If the response is not a digit
            return
        if int(number_received) < 1:
            # If there is no available slots
            print(f"Create a child process")
            self.agentInfo.commandsToSend.append("Fork\n")
        elif int(number_received) > 1:
            self.createChild()

    def forkManagement(self) -> None:
        """
        Manage the fork command
        Create a child process
        """
        if self.agentInfo.commandsReturned[0] != "Fork\n" or self.agentInfo.commandsReturned[1] == None:
            # There is no Fork command to manage or response has not been received
            return
        if self.agentInfo.commandsReturned[1].startswith("ok") == False:
            # If the response is not "ok"
            return
        print(f"Fork response: {self.agentInfo.commandsReturned[1]}")
        self.createChild()


    def broadcastManagement(self, data: str) -> bool:
        """
        Manage the broadcast
        Split data with ' ' ---> ["message", "K,", "text"]
        Agent can accept the incantation but need to broadcast answer
        """
        #if self.status == "Going to incantation":
        if data == None or data.startswith("message") == False or self.status == "Food":
            return False
        if "empty" in data:
            self.agentInfo.broadcast_received = "empty"
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

            self.acceptOrRefuseIncantation()
            self.playerOnSameTile()
            return True

            # print(f"Command to send {self.agentInfo.commandsToSend[-1]}")
        except Exception as e:
            print(f"Error from broadcast management: {e} from data: {data}")
            return False


    def acceptOrRefuseIncantation(self) -> None:
        """
        Accept or refuse the incantation, enter in this function only after receiving a broadcast
        """
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return
        if self.hasAcceptedIncantation == True: # If the agent has already accepted the incantation
            return
        try:
            if self.agentInfo.broadcast_received.startswith(f"need_incantation_level_{self.agentInfo.getLevel()}"): # If the agent receives a broadcast from another player asking for incantation
                if self.agentInfo.inventory["food"] >= 10:
                    #self.agentInfo.movements.clear()
                    #self.agentInfo.commandsToSend.clear()
                    self.agentInfo.commandsToSend.append(f"Broadcast accept_incantation_level_{self.agentInfo.getLevel()}\n")
                    self.hasAcceptedIncantation = True
                    self.status = "Going to incantation"
                    self.hasAskedIncantation = False
                    print(f"Accept incantation level {self.agentInfo.getLevel()} | current level: {self.agentInfo.level} | {self.agentInfo.inventory['food']=} | {self.hasAskedIncantation=} | {self.agentInfo.client_num=}")
                else:
                    print(f"Refuse incantation level {self.agentInfo.getLevel()} | current level: {self.agentInfo.level} | {self.agentInfo.inventory['food']=} | {self.hasAskedIncantation=} | {self.agentInfo.client_num=}")
                    self.status = "Food"
        except Exception as e:
            print(f"Error from acceptOrRefuseIncantation accept incantation: {e}")
            return

        try:
            # If the agent receives a broadcast to wait for incantation
            if self.hasAskedIncantation and self.agentInfo.incantationResponses < self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]:
                # If the agent has asked for incantation and has not enough responses
                self.isWaitingForResponses = True
                # print(f"Broadcast received: [{self.agentInfo.broadcast_received}], waiting: [accept_incantation_level_{str(self.agentInfo.getLevel())}], {self.agentInfo.incantationResponses=}")
                if self.agentInfo.broadcast_received.startswith(f"accept_incantation_level_{self.agentInfo.getLevel()}"):
                    self.agentInfo.incantationResponses += 1
        except Exception as e:
            print(f"Error from acceptOrRefuseIncantation count accept: {e}")
            return

    def waitingIncantationResponses(self) -> bool:
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return False
        if self.playerOnSameTileForIncantation >= self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]:
            return False
        if self.agentInfo.incantationResponses >= self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]: # If there is enough agent to evolve
            # wait until every players are ready and send incantation position with broadcast
            if f"Broadcast waiting_for_incantation_level_{self.agentInfo.getLevel() + 1}" not in self.agentInfo.commandsToSend: # check if boradcast waiting is not already sent in commandsToSend
                self.agentInfo.commandsToSend.append(f"Broadcast waiting_for_incantation_level_{self.agentInfo.getLevel() + 1}\n")
            return True
        return False


    def playerOnSameTile(self) -> None:
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return
        try:
            if self.agentInfo.broadcast_received.startswith("on_same_tile"):
                print(f"A player on same tile than incanter")
                self.playerOnSameTileForIncantation += 1
        except Exception as e:
            print(f"Error from playerOnSameTile broadcast received: {e}")
            return

        try:
            # print(f"Orientation of broadcast {self.agentInfo.broadcast_orientation} | received: {self.agentInfo.broadcast_received}")
            # If player receive broadcast orientation with message "waiting_for_incantation_level_n"
            if self.agentInfo.broadcast_orientation == "0" and self.agentInfo.broadcast_received.startswith(f"waiting_for_incantation_level_{self.agentInfo.getLevel() + 1}"):
                # Player is on the same tile as agent and has not already asked for incantation
                print(f"Orientation is 0 from broadcast {self.agentInfo.broadcast_received}")
                self.agentInfo.movements.clear()
                self.agentInfo.commandsToSend.clear()
                self.playerOnSameTileForIncantation += 1
                self.agentInfo.commandsToSend.append("Broadcast on_same_tile\n")
                self.status = "Waiting player to start incantation"
        except Exception as e:
            print(f"Error from playerOnSameTile broadcast orientation: {e}")
            return