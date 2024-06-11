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
import random
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
        self.status = "Continue"
        self.availableCommands = {"connect_nbr\n": ConnectCommand(), "forward\n": ForwardCommand(),
                                "right\n": RightCommand(), "left\n": LeftCommand(),
                                "look\n": LookCommand(), "inventory\n": InventoryCommand(),
                                "broadcast\n": BroadcastCommand(), "fork\n": ForkCommand(),
                                "eject\n": EjectCommand(), "take\n": TakeCommand(), "set\n": SetCommand(),
                                "incantation\n": IncantationCommand()}
        pass

    def updateAgentInfo(self, info: AgentInfo):
        self.agentInfo = info

    def updateClientStatus(self) -> None:
        """
        Update the client status.
        State could be: Continue, End, Dead, Incantation, Food
        """
        if len(self.alerts.checkAlerts()) == 0:
            return
        alert = self.alerts.checkAlerts().pop()
        if alert.startswith("incantation"):
            self.addCommandToExecuteInList(f"Broadcast {alert}\n")
            self.status = "Incantation"
            return
        if alert == "food":
            self.status = "Food"
            return
        self.status = "Continue"

    def clientPlayLevel1(self) -> None:
        """
        If the agent is level 1, do the actions for level 1
        Actions such as: search for food, search for resources, level up, etc
        """
        if self.agentInfo.getLevel() != 1:
            return
        self.foodMode() # Search for food

    def clientPlayLevel2(self) -> None:
        """
        If the agent is level 2, do the actions for level 2
        Actions such as: search for food, search for resources, level up, etc
        """
        if self.agentInfo.getLevel() != 2:
            return
        pass

    def clientPlayLevel3(self) -> None:
        """
        If the agent is level 3, do the actions for level 3
        Actions such as: search for food, help agent level 1 to upgrade to level 2, level up, etc
        """
        if self.agentInfo.getLevel() != 3:
            return
        pass

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
        inv = inv.replace("[ ", "")
        inv = inv.replace(" ]", "")
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
        self
        self.agentInfo.setTimeUnits(self.agentInfo.getInventory("food") * 126)
        return

    def foodMode(self) -> None:
        """
        The agent is in food mode, it will search for food
        """
        actions = ["Forward\n", "Right\n", "Forward\n", "Left\n"] # More chance to go forward (x2)

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
        actions = ["Forward\n", "Right\n", "Forward\n", "Left\n"] # More chance to go forward (x2)
        buf = self.getReturnCommand()[1]
        availables_resources = self.agentMoves.checkItems(buf, ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"])
        if availables_resources != []: # If there are resources to take
            item = random.choice(availables_resources)
            self.agentInfo.movements = self.agentMoves.reachItemList(item, buf)
            return
        else:
            finalAction = random.choice(actions)
            self.agentInfo.addCommandsToSend(finalAction)
            return

    def play(self, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        """
        self.updateClientStatus()
        if self.getReturnCommand()[0] == "Inventory\n":
            self.updateInventory(self.getReturnCommand()[1])
            for item, qt in self.agentInfo.inventory.items():
                print(f"{item}: {qt}")
            return
        if self.getReturnCommand()[0] == "Look\n" and self.status == "Food":
            print("Looking for food")
            self.foodMode()
            return
        if self.agentInfo.movements != []:
            self.agentInfo.addCommandsToSend(self.agentInfo.movements.pop(0))
            return
        if self.round == 10: # Frequency of inventory check
            print("list of commands to send: ", self.agentInfo.commandsToSend)
            self.agentInfo.commandsToSend.insert(0, "Inventory\n")
            self.round = 0
            return
        #if self.agentMentality == "Incantation":
        #    return
        #if self.agentMentality == "Hungry":
        #    return None
        self.round += 1
        #print(f"Status: {self.status}")
        if self.status == "Food":
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.commandsToSend.insert(0, "Look\n")
            return
        if self.status == "Incantation" or self.status == "Dead" or self.status == "End":
            return # If the agent is in incantation, dead or end state, do nothing
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

    def findBestItemToTake(self, playerLevel: int) -> str:
        """
        Find the best item to take according to the player level
        """
        # If there are multiple items with the same quantity, choose best item for player level
        if playerLevel == 1:
            return "linemate"
        elif playerLevel == 2:
            if self.agentInfo.inventory["linemate"] < 2:
                return "linemate"
            if self.agentInfo.inventory["deraumere"] < 1:
                return "deraumere"
            return "sibur"
        elif playerLevel == 3:
            if self.agentInfo.inventory["phiras"] < 2:
                return "phiras"
            if self.agentInfo.inventory["linemate"] < 2:
                return "linemate"
            return "sibur"
        elif playerLevel == 4:
            if self.agentInfo.inventory["sibur"] < 2:
                return "sibur"
            if self.agentInfo.inventory["phiras"] < 1:
                return "phiras"
            if self.agentInfo.inventory["deraumere"] < 1:
                return "deraumere"
            return "linemate"
        elif playerLevel == 5:
            if self.agentInfo.inventory["mendiane"] < 3:
                return "mendiane"
            if self.agentInfo.inventory["sibur"] < 1:
                return "sibur"
            if self.agentInfo.inventory["deraumere"] < 1:
                return "deraumere"
            return "linemate"
        elif playerLevel == 6:
            if self.agentInfo.inventory["sibur"] < 3:
                return "sibur"
            if self.agentInfo.inventory["phiras"] < 1:
                return "phiras"
            if self.agentInfo.inventory["deraumere"] < 2:
                return "deraumere"
            return "linemate"
        elif playerLevel == 7:
            if self.agentInfo.inventory["phiras"] < 2:
                return "phiras"
            if self.agentInfo.inventory["thystame"] < 1:
                return "thystame"
            if self.agentInfo.inventory["mendiane"] < 2:
                return "mendiane"
            if self.agentInfo.inventory["sibur"] < 2:
                return "sibur"
            if self.agentInfo.inventory["deraumere"] < 2:
                return "deraumere"
            return "linemate"
        else:
            return "linemate"
