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
        self.port = port
        self.team_name = team_name
        self.ip = ip
        self.client = None
        self.availableCommands = {"connect_nbr": ConnectCommand(), "forward": ForwardCommand(),
                                "right": RightCommand(), "left": LeftCommand(),
                                "look": LookCommand(), "inventory": InventoryCommand(),
                                "broadcast": BroadcastCommand(), "fork": ForkCommand(),
                                "eject": EjectCommand(), "take": TakeCommand(), "set": SetCommand(),
                                "incantation": IncantationCommand()}

    def executeCommand(self, command: str) -> None:
        """Execute a command"""
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
        except Exception as e:
            print(f"Error: {e}")
            exit(84)


    def send_to_server(self, message: str) -> None:
        """Send a message to the server"""
        self.client.send(message.encode())

    def disconnect_from_server(self) -> None:
        """Disconnect from the server"""
        self.client.close()
