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
from collections import deque
import select

from models.AgentInfo import AgentInfo
from models.AgentAction import AgentAction
from models.AgentAlgo import AgentAlgo

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
        self.client = None
        self.agentInfo = AgentInfo()
        self.agentAction = AgentAction(self.agentInfo)
        self.agentAlgo = AgentAlgo(self.agentInfo, 100)
        self.agentAlgo = None
        self.port = port
        self.team_name = team_name
        self.receive_from_server = None
        self.ip = ip
        self.availableCommands = {"connect_nbr\n": ConnectCommand(), "forward\n": ForwardCommand(),
                                "right\n": RightCommand(), "left\n": LeftCommand(),
                                "look\n": LookCommand(), "inventory\n": InventoryCommand(),
                                "broadcast\n": BroadcastCommand(), "fork\n": ForkCommand(),
                                "eject\n": EjectCommand(), "take\n": TakeCommand(), "set\n": SetCommand(),
                                "incantation\n": IncantationCommand()}

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
            self.agentAlgo = AgentAlgo(self.agentInfo, 100, self.client)
            # self.client.setblocking(0)
            while True:
                # self.agentAlgo = AgentAlgo(self.agentInfo, 100, self.client)
                self.receive_from_server = self.client.recv(1024).decode()
                if self.disconnect_from_server(self.receive_from_server):
                    break
                if self.receive_from_server == "WELCOME\n": # If the server sends "WELCOME\n", send the team name
                    self.client.send(f"{self.team_name}\n".encode())

                self.retrieveClientNumber(self.receive_from_server)
                self.retrieveWorldDimensions(self.receive_from_server)
                # self.agentAlgo.play(self.agentInfo, self.receive_from_server)
                self.addCommandToExecuteInList(self.receive_from_server)
                self.agentAlgo.send_to_server()
        except Exception as e:
            print(f"Error: {e}")
            exit(84)

    def disconnect_from_server(self, data: str) -> bool:
        """Disconnect from the server"""
        if data == "ko\n" or data == "dead\n": # If the server sends "ko\n" or "dead\n", close the connection
            self.client.close()
            return True
        return False
