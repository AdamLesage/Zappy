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
    def __init__(self, agentInfo: AgentInfo, fTime: int, client: socket, ip: str, port: int, teamName: str):
        self.alerts = AgentAlerts(agentInfo, fTime)
        self.agentInfo = agentInfo
        self.agentMoves = Moves()
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
        pass

    def updateAgentInfo(self, info: AgentInfo):
        self.agentInfo = info

    def updateClientStatus(self, round: int) -> None:
        """
        Update the client status.
        State could be: Continue, End, Dead, Incantation, Food
        """
        if len(self.alerts.checkAlerts()) == 0:
            return
        alert = self.alerts.checkAlerts().pop()
        if alert.startswith("incantationNeeded"):
            if alert != "incantationNeeded_2": # Not needed for incantation to level 2
                self.addCommandToExecuteInList(f"Broadcast {alert}\n")
            self.status = "Incantation"
            return
        if alert == "food":
            self.status = "Food"
            return

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
        inv = inv.replace("[ ", "")
        inv = inv.replace(" ]", "")
        inv = inv.replace("[", "")
        inv = inv.replace("]", "")
        inv = inv.replace(", ", ",")
        splitedInf = inv.split(',')

        for item in splitedInf:
            item = item.split(' ')
            if self.agentInfo.inventory[item[0]] == int(item[1]):
                continue
            self.agentInfo.addInventory(item[0], item[1])
        self.agentInfo.setTimeUnits(self.agentInfo.getInventory("food") * 126)

    def foodMode(self) -> None:
        """
        The agent is in food mode, it will search for food
        """
        actions = ["Forward\n", "Right\n", "Forward\n", "Left\n"] # More chance to go forward (x2)
        if self.agentInfo.getInventory("food") > 20:
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
        if self.status == "Incantation":
            self.round = 0
            return False
        if self.round == 10: # Frequency of inventory check, avoid to check inventory if incantation is in progress
            self.agentInfo.commandsToSend.insert(0, "Inventory\n")
            self.round = 0
            return True
        return False

    def goToBroadcast(self, orientation: str) -> None:
        """
        Player will go to the broadcast position and add the movements to the movements list
        """
        self.agentInfo.commandsToSend.clear()
        self.agentInfo.movements.clear()
        if orientation == "0": # Player is on the broadcast position
            return
        elif orientation == "1": # Broadcast position is on the north of the player
            self.agentInfo.movements.append("Forward\n")
        elif orientation == "2": # Broadcast position is on north-west of the player
            self.agentInfo.movements.append("Forward\n")
            self.agentInfo.movements.append("Left\n")
            self.agentInfo.movements.append("Forward\n")
        elif orientation == "3": # Broadcast position is on the west of the player
            self.agentInfo.movements.append("Left\n")
            self.agentInfo.movements.append("Forward\n")
        elif orientation == "4": # Broadcast position is on the north-west of the player
            self.agentInfo.movements.append("Left\n")
            self.agentInfo.movements.append("Forward\n")
            self.agentInfo.movements.append("Left\n")
            self.agentInfo.movements.append("Forward\n")
        elif orientation == "5": # Broadcast position is on the south of the player
            self.agentInfo.movements.append("Left\n")
            self.agentInfo.movements.append("Left\n")
            self.agentInfo.movements.append("Forward\n")
        elif orientation == "6": # Broadcast position is on the south-east of the player
            self.agentInfo.movements.append("Right\n")
            self.agentInfo.movements.append("Forward\n")
            self.agentInfo.movements.append("Right\n")
            self.agentInfo.movements.append("Forward\n")
        elif orientation == "7": # Broadcast position is on the east of the player
            self.agentInfo.movements.append("Right\n")
            self.agentInfo.movements.append("Forward\n")
        elif orientation == "8": # Broadcast position is on the north-east of the player
            self.agentInfo.movements.append("Forward\n")
            self.agentInfo.movements.append("Right\n")
            self.agentInfo.movements.append("Forward\n")

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

    def incantationManagement(self) -> None:
        if self.status != "Incantation":
            self.round += 1 # Increment the round
            return
        if self.hasAskedIncantation == False:
            # Ask for incantation
            self.hasAskedIncantation = True
            self.agentInfo.commandsToSend.clear()
            self.setItemsForIncantation()
            if self.agentInfo.getLevel() != 1:
                self.agentInfo.commandsToSend.append("Broadcast need_incantation_level_" + str(self.agentInfo.getLevel()) + "\n")
            self.agentInfo.commandsToSend.append("Incantation\n")
        if self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("Current level:"): # If the incantation is a success
            self.hasAskedIncantation = False
            self.status = "Mining"
            self.agentInfo.setLevel(self.agentInfo.getLevel() + 1)
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.commandsToSend.append("Broadcast incantation_success_level_" + str(self.agentInfo.getLevel()) + "\n")
            self.agentInfo.commandsToSend.append("Look\n")
            self.round = 0
            pid = os.fork()
            if pid > 0:
                print(f"Parent process: {os.getpid()}") # Parent process
            else:
                print(f"Child process: {os.getpid()}")
                self.agentInfo.commandsToSend.clear()
                os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.teamName, "-h", self.ip])
        elif self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("ko"): # If the incantation is a failure
            self.hasAskedIncantation = False
            self.status = "Food"
            print(f"Failure incantation for level {self.agentInfo.getLevel()}, going back to mining")
            self.agentInfo.commandsToSend.append("Inventory\n")
            self.round = 0

    def forkMode(self, round: int) -> None:
        """
        Will check if the agent can fork.
        If yes, it will fork the agent.
        """
        print(f"Availables slots for the team: {self.agentInfo.availableSlots}")
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
                self.agentInfo.commandsToSend.clear()
                os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.teamName, "-h", self.ip])
            return False
        if self.getReturnCommand()[0] == "Connect_nbr\n" and int(self.getReturnCommand()[1].replace("\n", "")) != 0:
            print(f"Connect_nbr: {self.getReturnCommand()[1]}")
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.addCommandsToSend("Fork\n")
            return True
        elif round == 5 and self.status == "Mining":
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.addCommandsToSend("Connect_nbr\n")
            return True
        return False
    
    def inventoryManagement(self) -> bool:
        """
        Check the inventory of the agent:
        - Send the command "Inventory" to the server.
        - Update the inventory of the agent.
        """
        if self.getReturnCommand()[0] == "Inventory\n":
            self.updateInventory(self.getReturnCommand()[1])
            # for item, qt in self.agentInfo.inventory.items():
            #     print(f"{item}: {qt}")
            self.round = 0
            return False
        if self.round >= 10 and self.status != "Incantation": # Frequency of inventory check, avoid to check inventory if incantation is in progress
            self.agentInfo.commandsToSend.insert(0, "Inventory\n")
            return True
        return False

    def play(self, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        """
        # print(f"Status: {self.status}, level {self.agentInfo.getLevel()}")
        self.updateClientStatus(self.round)
        self.round += 1
        if self.round == 5:
            self.agentInfo.commandsToSend.insert(0, "Connect_nbr\n")
        if self.inventoryManagement():
            return
        if self.getReturnCommand()[0] == "Look\n" and self.status == "Food":
            self.foodMode()
            return
        if self.agentInfo.movements != []:
            self.agentInfo.addCommandsToSend(self.agentInfo.movements.pop(0))
            return
        self.agentInfo.manageBroadcastReceived()
        if self.checkInventory() == True:
            return
        self.incantationManagement()
        if self.status == "Food":
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.commandsToSend.insert(0, "Look\n")
            return
        if self.status == "Mining":
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.commandsToSend.insert(0, "Look\n")
        self.clientPlayLevel1()
        self.clientPlayLevel2()
        self.clientPlayLevel3()
        self.clientPlayLevel4()
        self.clientPlayLevel5()
        self.clientPlayLevel6()
        self.clientPlayLevel7()
        self.clientPlayLevel8()
        return

    def send_to_server(self) -> None:
        """Send a message to the server"""
        if self.agentInfo.commandsReturned[0] != None:
            return None
        if self.agentInfo.commandsToSend == deque([]) or self.client == None: # If there are no commands to send, get out of the function
            return None
        command_to_send = self.agentInfo.commandsToSend.popleft()
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

    def setReturnCommandAnswer(self, serverAnswer: str) -> None:
        """Set the command to return"""
        self.agentInfo.commandsReturned[1] = serverAnswer
    
    def getReturnCommand(self) -> str:
        """Get the command to return"""
        return self.agentInfo.commandsReturned
    
    def clearReturnCommand(self) -> None:
        """Clear the command to return"""
        self.agentInfo.commandsReturned = [None, None]

    def broadcastManagement(self, data: str) -> None:
        """
        Manage the broadcast
        Split data with ' ' ---> [""message", "K,", "text]
        Agent can accept or refuse the incantation but need to broadcast answer
        """
        if data == None or data.startswith("message") == False:
            return None
        data = data.replace(",", "") # remove comma after K
        data = data.replace("\n", "") # remove \n at the end of the string
        incantationLevel = 0
        try:
            self.agentInfo.broadcast_orientation = data.split(' ')[1]
            self.agentInfo.broadcast_received = data.split(' ')[2]

            if self.agentInfo.broadcast_received.startswith("incantation_success_level_"):
                incantationLevel = int(self.agentInfo.broadcast_received.split('_')[-1])
                self.agentInfo.teamPlayers[f"level{incantationLevel}"] += 1
            if self.agentInfo.broadcast_received.startswith("need_incantation_level_"):
                incantationLevel = int(self.agentInfo.broadcast_received.split('_')[-1])
                if self.agentInfo.getLevel() == incantationLevel - 1:
                    self.agentInfo.commandsToSend.append(f"Broadcast accept_incantation_level_{str(incantationLevel)}\n")
                else:
                    self.agentInfo.commandsToSend.append(f"Broadcast refuse_incantation_level_{str(incantationLevel)}\n")
                print(f"Command to send {self.agentInfo.commandsToSend[-1]}")
        except Exception as e:
            print(f"Error from broadcast management: {e}")
