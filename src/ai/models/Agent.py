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

    def connect_to_server(self) -> None:
        """Connect to the server from the given ip and port"""
        try:
            self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client.connect((self.ip, self.port))
            while True:
                data = self.client.recv(1024).decode()
                print(f"Received: {data}")
                message = input(" > ")
                self.send_to_server(message)
        except Exception as e:
            print(f"Error: {e}")
            exit(84)


    def send_to_server(self, message: str) -> None:
        """Send a message to the server"""
        self.client.send(message.encode())

    def disconnect_from_server(self) -> None:
        """Disconnect from the server"""
        self.client.close()
