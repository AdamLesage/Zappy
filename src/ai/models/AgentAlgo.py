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
        self.round = 0
        self.ip = ip
        self.port = port
        self.teamName = teamName
        self.agentMentality = "None" #Hungry, Incantation, Mining, None
        self.status = "Mining"
        self.hasAskedIncantation = False
        self.availableCommands = {"connect_nbr\n": ConnectCommand(), "forward\n": ForwardCommand(),
                                "right\n": RightCommand(), "left\n": LeftCommand(),
                                "look\n": LookCommand(), "inventory\n": InventoryCommand(),
                                "broadcast\n": BroadcastCommand(), "fork\n": ForkCommand(),
                                "eject\n": EjectCommand(), "take\n": TakeCommand(), "set\n": SetCommand(),
                                "incantation\n": IncantationCommand()}
        self.countRoundForIncantation = 0
        self.playerOnSameTileForIncantation = 1
        self.isWaitingForResponses = False
        self.hasAskedPlayerConnected = False
        self.isPlayerConnected = False
        self.borntick = 0
        self.alReadyResponded = False
        self.broadcastReceived = None # Broadcast received from the server
        pass

    def updateAgentInfo(self, info: AgentInfo):
        self.agentInfo = info

    def updateClientStatus(self, round: int) -> None:
        """
        Update the client status.
        State could be: Continue, End, Dead, Incantation, Food
        """
        try:
            if len(self.alerts.checkAlerts()) == 0:
                return
            alert = self.alerts.checkAlerts().pop()
            if alert.startswith("incantationNeeded"):
                if alert != "incantationNeeded_2": # Not needed for incantation to level 2
                    self.agentInfo.commandsToSend.append(f"Broadcast {alert}\n")
                self.status = "Incantation" # Do not change status to incantation, need to wait for other agents except if player is level 1 
                return
            if alert == "food":
                self.status = "Food"
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
        else:
            self.miningMode()

    def clientPlayLevel3(self) -> None:
        """
        If the agent is level 3, do the actions for level 3
        Actions such as: search for food, help agent level 1 to upgrade to level 2, level up, etc
        """
        if self.agentInfo.getLevel() != 3:
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        elif self.status == "Incantation":
            return # If the agent is in incantation, do nothing because broadcast has been sent, need to wait for other agents
        else:
            self.miningMode()

    def clientPlayLevel4(self) -> None:
        """
        If the agent is level 4, do the actions for level 4
        Actions such as: search for food, help agent level 2 to upgrade to level 3, level up, etc
        Once level 4 is reached, agent is considered as a "helper" agent
        Then once there is enough agents to reach level 5, he will join or start an incantation to level 5
        """
        if self.agentInfo.getLevel() != 4:
            return
        pass

    def clientPlayLevel5(self) -> None:
        """
        If the agent is level 5, do the actions for level 5
        Actions such as: search for food, help agent level 3 to upgrade to level 4, level up, etc
        """
        if self.agentInfo.getLevel() != 5:
            return
        pass

    def clientPlayLevel6(self) -> None:
        """
        If the agent is level 6, do the actions for level 6
        Actions such as: search for food, help agent level 4 and level 5 to upgrade to level 6, level up, etc
        The goal of agent level 6 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 6:
            return
        pass

    def clientPlayLevel7(self) -> None:
        """
        If the agent is level 7, do the actions for level 7
        Actions such as: search for food, help agent and level 4, level 5 and level 6 to upgrade to level 7, level up, etc
        The goal of agent level 7 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 7:
            return
        pass

    def clientPlayLevel8(self) -> None:
        """
        If the agent is level 8, do the actions for level 8
        Actions such as: search for food, help agent and level 4, level 5, level 6 and level 7 to upgrade to level 8, level up, etc
        The goal of agent level 8 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 8:
            return
        pass

    def updateInventory(self, inv: str) -> None:
        """
        Update the inventory of the agent
        """
        # return if there is not digit in the inv string
        if any(char.isdigit() for char in inv) == False:
            return
        # if inv contains "player" return
        if "player" in inv or "message" in inv: # If the inventory contains "player" or "message"
            return
        try:
            inv = inv.replace("[ ", "").replace(" ]", "").replace("[", "").replace("]", "").replace(", ", ",")
            splitedInf = inv.split(',')

            for item in splitedInf:
                item = item.split(' ')
                if self.agentInfo.inventory[item[0]] == int(item[1]):
                    continue
                self.agentInfo.addInventory(item[0], item[1])
            self.agentInfo.setTimeUnits(self.agentInfo.getInventory("food") * 126)
        except Exception as e:
            print(f"Error from updateInventory: {e}")

    def foodMode(self) -> None:
        """
        The agent is in food mode, it will search for food
        """
        actions = ["Forward\n", "Right\n", "Forward\n", "Left\n"] # More chance to go forward (x2)
        if self.agentInfo.getInventory("food") > 10:
            self.status = "Mining"
            return
        buf = self.getReturnCommand()[1]
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
        actions = ["Forward\n", "Right\n", "Left\n"] # More chance to go forward (x2)
        buf = self.getReturnCommand()[1]
        if buf != None and self.agentMoves.checkItems(buf, ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]) != []: # If there are resources to take
            availables_resources = self.agentMoves.checkItems(buf, ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"])
            item = self.agentMoves.findBestItemToTake(self.agentInfo, self.agentInfo.getLevel(), availables_resources)
            self.agentInfo.movements = self.agentMoves.reachItemList(item, buf)
            return
        else:
            finalAction = random.choice(actions)
            self.agentInfo.addCommandsToSend(finalAction)
            return

    def checkInventory(self) -> bool:
        """
        Check the inventory of the agent every 10 rounds
        """
        try:
            if self.status == "Incantation":
                self.round = 0
                return False
            if self.round == 10: # Frequency of inventory check, avoid to check inventory if incantation is in progress
                self.agentInfo.commandsToSend.append("Inventory\n")
                self.round = 0
                return True
            return False
        except Exception as e:
            print(f"Error from checkInventory: {e}")
            return False

    def setItemsForIncantation(self) -> None:
        """
        Set the items to take for the incantation
        """
        # TODO: look before setting everything to avoid to take the same item twice
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

    def createChild(self) -> None:
        pid = os.fork()
        if pid > 0:
            print(f"Parent process: {os.getpid()}") # Parent process
        else:
            print(f"Child process: {os.getpid()}")
            os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.teamName, "-h", self.ip])

    def incantationManagement(self) -> None:
        if self.status != "Incantation" and self.status != "Waiting player to start incantation" and self.status != "Is on incantation":
            self.round += 1 # Increment the round
            return
        # If agent do not receive accept fast, back to take food
        # if self.countRoundForIncantation >= 20_000 and self.isWaitingForResponses == True:
        #     self.hasAskedIncantation = False
        #     self.countRoundForIncantation = 0
        #     self.status = "Food"
        #     self.agentInfo.commandsToSend.append("Inventory\n")
        #     return
        self.waitingIncantationResponses()
        self.countRoundForIncantation += 1
        if self.hasAskedIncantation == False:
            # Ask for incantation
            self.hasAskedIncantation = True
            if self.agentInfo.getLevel() != 1:
                self.agentInfo.commandsToSend.append("Broadcast need_incantation_level_" + str(self.agentInfo.getLevel()) + "\n")
                print(f"Broadcast need_incantation_level_{self.agentInfo.getLevel()}")
            self.countRoundForIncantation = 0
            if self.playerOnSameTileForIncantation == self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]: # If there is enough agent to evolve
                # TODO: fix change logic to start incantation
                print(f"Player level {self.agentInfo.getLevel()} has asked for incantation")
                self.setItemsForIncantation()
                self.agentInfo.commandsToSend.append("Incantation\n")
                self.playerOnSameTileForIncantation = 1
        if self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("Current level:"): # If the incantation is a success
            self.hasAskedIncantation = False
            self.status = "Mining"
            self.agentInfo.setLevel(self.agentInfo.getLevel() + 1)
            self.countRoundForIncantation = 0
            self.agentInfo.commandsToSend.append("Look\n")
            self.agentInfo.incantationResponses = 1
            self.round = 0
            pid = os.fork()
            if pid > 0:
                self.agentInfo.addCommandsToSend("Fork\n")
            else:
                os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.teamName, "-h", self.ip])
        elif self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("ko"): # If the incantation is a failure
            self.hasAskedIncantation = False
            self.status = "Food"
            self.agentInfo.commandsToSend.append("Inventory\n")
            self.round = 0

    def forkMode(self, round: int) -> None:
        """
        Will check if the agent can fork.
        If yes, it will fork the agent.
        """
        if len(self.alerts.checkAlerts()) != 0:
            alert = self.alerts.checkAlerts().pop()
            if alert == "food":
                return False
        if self.getReturnCommand()[0] == "Fork\n":
            pid = os.fork()
            if pid > 0:
                print(f"Parent process: {os.getpid()}") # Parent process
            else:
                print(f"Child process: {os.getpid()}")
                os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.teamName, "-h", self.ip])
            return False
        if self.getReturnCommand()[0] == "Connect_nbr\n" and int(self.getReturnCommand()[1].replace("\n", "")) != 0:
            print(f"Connect_nbr: {self.getReturnCommand()[1]}")
            self.agentInfo.addCommandsToSend("Fork\n")
            return True
        else:
            self.agentInfo.addCommandsToSend("Connect_nbr\n")
            return True
    
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
                self.updateInventory(command_output[1])
                self.round = 0
                return False
            
            if self.round >= 10 and self.status != "Incantation": # Frequency of inventory check, avoid to check inventory if incantation is in progress
                self.agentInfo.commandsToSend.append("Inventory\n")
                return True
            
            return False
        except ValueError as e:
            print(f"Error from inventoryManagement: {e}")
            return False


    def play(self, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        """
        # print(f"Status: {self.status}, level {self.agentInfo.getLevel()}")
        if self.status == "Waiting player to start incantation":
            return
        try:
            if self.agentBroadcast.goToBroadcast(self.agentInfo.broadcast_orientation, self.agentInfo, self.status) == True:
                return
            self.updateClientStatus(self.round)
            self.round += 1
            # self.borntick += 1
            if self.round == 5 and "incantation" not in self.status:
                self.agentInfo.commandsToSend.append("Connect_nbr\n")
            if self.inventoryManagement():
                return
            self.agentBroadcast.goToBroadcast(self.agentInfo.broadcast_orientation, self.agentInfo, self.status)
            if self.getReturnCommand()[0] == "Look\n" and self.status == "Food":
                self.foodMode()
                return
            if self.agentInfo.movements != []:
                self.agentInfo.addCommandsToSend(self.agentInfo.movements.pop(0))
                return
            if self.checkInventory() == True:
                return
            self.incantationManagement()
            if self.status == "Food":
                self.agentInfo.commandsToSend.append("Look\n")
                return
            if self.status == "Mining":
                self.agentInfo.commandsToSend.append("Look\n")
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
        tmp = [command_to_send, None]
        self.agentInfo.commandsReturned = tmp
        # Add first command from waiting list to the commandsToSend list

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
        Split data with ' ' ---> [""message", "K,", "text]
        Agent can accept or refuse the incantation but need to broadcast answer
        """
        if data == None or data.startswith("message") == False:
            return False
        self.broadcastReceived = data
        data = data.replace(",", "") # remove comma after K
        data = data.replace("\n", "") # remove \n at the end of the string
        try:
            self.agentInfo.broadcast_received = data.split(' ')[2]
            self.agentInfo.broadcast_orientation = data.split(' ')[1]

            self.acceptOrRefuseIncantation()
            self.playerOnSameTile()
            return True

            # print(f"Command to send {self.agentInfo.commandsToSend[-1]}")
        except Exception as e:
            print(f"Error from broadcast management: {e}")
            return False
        return False


    def acceptOrRefuseIncantation(self) -> None:
        """
        Accept or refuse the incantation, enter in this function only after receiving a broadcast
        """
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return
        incantationLevel = 0
        try:
            if self.agentInfo.broadcast_received.startswith("need_incantation_level_") and self.status != "Going to incantation": # If the agent receives a broadcast to ask for incantation
                incantationLevel = int(self.agentInfo.broadcast_received.split('_')[-1])
                if self.agentInfo.getLevel() == incantationLevel and self.hasAskedIncantation == False and self.agentInfo.inventory["food"] > 10:
                    print(f"Accept incantation level {incantationLevel}")
                    self.agentInfo.commandsToSend.append(f"Broadcast accept_incantation_level_{incantationLevel}\n")
                    self.status = "Going to incantation"
        except Exception as e:
            print(f"Error from acceptOrRefuseIncantation accept incantation: {e}")
            return

        try:
            # If the agent receives a broadcast to wait for incantation
            if self.hasAskedIncantation and self.agentInfo.incantationResponses < self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]:
                # If the agent has asked for incantation and has not enough responses
                self.isWaitingForResponses = True
                # print(f"Broadcast received: [{self.agentInfo.broadcast_received}], waiting: [accept_incantation_level_{str(self.agentInfo.getLevel())}], {self.agentInfo.incantationResponses=}")
                if self.agentInfo.broadcast_received == f"accept_incantation_level_{self.agentInfo.getLevel()}":
                    self.agentInfo.incantationResponses += 1
                    print(f"A player accepted incantation level {self.agentInfo.getLevel() + 1}, {self.agentInfo.incantationResponses=} --> need {self.agentInfo.numberToEvolve[f'level{self.agentInfo.getLevel() + 1}']}")
        except Exception as e:
            print(f"Error from acceptOrRefuseIncantation count accept: {e}")
            return

        if self.agentInfo.broadcast_received.startswith("need_incantation_level_"): # If the agent receives a broadcast to ask for incantation
            incantationLevel = int(self.agentInfo.broadcast_received.split('_')[-1])
            if self.agentInfo.getLevel() == incantationLevel:
                print(f"Accept incantation level {incantationLevel}")
                self.agentInfo.commandsToSend.append(f"Broadcast accept_incantation_level_{str(incantationLevel)}\n")
                self.status = "Going to incantation"
            # else:
            #     print(f"Refuse incantation level {incantationLevel}")
    
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
            print(f"Broadcast yes_we_are_on_the_map")
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
        print(f"Broadcast Anybody_on_the_map_?")
        self.hasAskedPlayerConnected = True

    def waitingIncantationResponses(self) -> None:
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return
        if self.agentInfo.incantationResponses >= self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]: # If there is enough agent to evolve
            # wait until every players are ready and send incantation position with broadcast
            self.agentInfo.commandsToSend.append(f"Broadcast waiting_for_incantation_level_{self.agentInfo.getLevel() + 1}\n")
        pass

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
    
    def playerOnSameTile(self) -> None:
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return
        try:
            if self.agentInfo.broadcast_received == "on_same_tile":
                print(f"A player on same tile than incanter")
                self.playerOnSameTileForIncantation += 1
                next_level = self.agentInfo.getLevel() + 1
                required_players = self.agentInfo.numberToEvolve[f"level{next_level}"]
                if self.playerOnSameTileForIncantation >= required_players:
                    print(f"Player can start an incantation level {next_level}")
                    self.clearReturnCommand()
                    self.agentInfo.commandsToSend.clear()
                    self.agentInfo.commandsToSend.append(f"Incantation\n")
                    self.status = "Is on incantation"
        except Exception as e:
            print(f"Error from playerOnSameTile broadcast received: {e}")
            return

        try:
            # If player receive broadcast orientation with message "waiting_for_incantation_level_n"
            if self.agentInfo.broadcast_orientation == "0" and self.agentInfo.broadcast_received == f"waiting_for_incantation_level_{self.agentInfo.getLevel() + 1}\n":
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
