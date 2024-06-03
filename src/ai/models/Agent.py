##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Agent
##

import socket
import sys
sys.path.append("..")
from data_encryption import encrypt_data, decrypt_data
from models.AgentInfo import AgentInfo
# from models.AgentAlert import AgentAlert
from models.AgentAction import AgentAction
from collections import deque

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

class Agent():
    def __init__(self, port: int, team_name: str, ip: str = "localhost"):
        self.agentInfo = AgentInfo()
        self.agentAction = AgentAction(self.agentInfo)
        # self.agentAlert = AgentAlert(self.agentInfo)
        self.port = port
        self.team_name = team_name
        self.ip = ip
        self.client = None
        self.availableCommands = {"connect_nbr\n": ConnectCommand(), "forward\n": ForwardCommand(),
                                "right\n": RightCommand(), "left\n": LeftCommand(),
                                "look\n": LookCommand(), "inventory\n": InventoryCommand(),
                                "broadcast\n": BroadcastCommand(), "fork\n": ForkCommand(),
                                "eject\n": EjectCommand(), "take\n": TakeCommand(), "set\n": SetCommand(),
                                "incantation\n": IncantationCommand()}

    def executeCommand(self, command: str) -> None:
        """Execute a command"""
        if command not in self.availableCommands:
            return
        command = self.availableCommands[command].execute(self.client)
        self.agentInfo.addCommandsToSend(command) # Add the command to the list of commands to send

    def retrieveWorldDimensions(self, data: str) -> None:
        """Retrieve the world dimensions"""
        if self.agentInfo.world_width != 0 and self.agentInfo.world_height != 0 or len(data[0:len(data) - 1].split('\n')) != 2:
            return
        splited_data = data[0:len(data) - 1].split('\n')
        splited_x = splited_data[1].split(' ')[0]
        splited_y = splited_data[1].split(' ')[1]

        if splited_x.isdigit() and splited_y.isdigit():
            self.agentInfo.world_width = int(splited_x)
            self.agentInfo.world_height = int(splited_y)
        print(f"World dimensions: {self.agentInfo.world_width}x{self.agentInfo.world_height}")

    def retrieveClientNumber(self, data: str) -> None:
        """Retrieve the client number"""
        if self.agentInfo.client_num != 0:
            return
        splited_client_numero = data[0:len(data) - 1].split('\n')[0]
        if splited_client_numero.isdigit():
            client_num = int(splited_client_numero)
            if client_num >= 1:
                print(f"Connected as client {client_num}")
                self.agentInfo.client_num = client_num
            else:
                print("No available slots for the team")
                exit(1)

    def connect_to_server(self) -> None:
        """Connect to the server from the given ip and port"""
        try:
            self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client.connect((self.ip, self.port))
            while True:
                data = self.client.recv(1024).decode()
                if data == "WELCOME\n": # If the server sends "WELCOME\n", send the team name
                    self.client.send(f"{self.team_name}\n".encode())

                self.retrieveClientNumber(data)
                self.retrieveWorldDimensions(data)
                self.executeCommand(data)
                self.send_to_server()
                self.play()
                if self.disconnect_from_server(data):
                    break
        except Exception as e:
            print(f"Error: {e}")
            exit(84)

    def play(self) -> None:
        """Play the game, search for resources, level up, incantation, etc"""
        # alerts = self.agentAlert.checkAlerts()
        # self.agentAction.useAlerts(alerts)
        pass

    def send_to_server(self) -> None:
        """Send a message to the server"""
        if self.agentInfo.commandsToSend == deque([]):
            return
        command_to_send = self.agentInfo.commandsToSend.popleft()
        print(f"Sending command: {command_to_send}")
        self.client.sendall(command_to_send.encode())

    def disconnect_from_server(self, data: str) -> bool:
        """Disconnect from the server"""
        if data == "ko\n" or data == "dead\n":
            self.client.close()
            return True
        return False
