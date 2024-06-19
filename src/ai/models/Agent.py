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
import os

from models.AgentInfo import AgentInfo
from models.AgentAction import AgentAction
from models.AgentAlgo import AgentAlgo

class Agent():
    def __init__(self, port: int, team_name: str, ip: str = "localhost"):
        self.client = None
        self.agentInfo = AgentInfo()
        self.agentAction = AgentAction(self.agentInfo)
        self.agentAlgo = None
        self.port = port
        self.team_name = team_name
        self.receive_from_server = None
        self.ip = ip
        self.firstConnexion = True

    def retrieveWorldDimensions(self, data: str) -> None:
        """Retrieve the world dimensions"""
        if data == None:
            return
        if self.agentInfo.world_width != 0 and self.agentInfo.world_height != 0 or len(data[0:len(data) - 1].split('\n')) != 2:
            return
        splited_data = data[0:len(data) - 1].split('\n')
        splited_x = splited_data[1].split(' ')[0]
        splited_y = splited_data[1].split(' ')[1]

        if splited_x.isdigit() and splited_y.isdigit():
            self.agentInfo.world_width = int(splited_x)
            self.agentInfo.world_height = int(splited_y)

    def retrieveClientNumber(self, data: str) -> None:
        """Retrieve the client number"""
        if data == None:
            return
        if self.agentInfo.client_num != 0:
            return
        splited_client_numero = data[0:len(data) - 1].split('\n')[0]
        if splited_client_numero.isdigit():
            client_num = int(splited_client_numero)
            if client_num >= 1:
                print(f"Connected as client {client_num}")
                self.agentInfo.client_num = client_num
            else:
                # TODO: check up sometimes to see if there is a slot available and fork if not
                print(f"Player is not allowed to connect to the server with client number {client_num}")
                exit(1)

    def connect_to_server(self) -> None:
        """Connect to the server from the given ip and port"""
        try:
            tmp = 0
            self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client.connect((self.ip, self.port))
            self.agentAlgo = AgentAlgo(self.agentInfo, 1260, self.client, self.ip, self.port, self.team_name)
            self.client.setblocking(0) # Do not wait for the server to send data

            while True:
                try:
                    try:
                        self.receive_from_server = self.client.recv(1024).decode()
                        # if self.receive_from_server.count('\n') == 0:
                        #     continue
                        if self.agentAlgo.broadcastManagement(self.receive_from_server.replace("\n", "")) == True:
                            continue
                        # print(f"tmp {tmp} | {self.receive_from_server} after send {self.agentInfo.getCommandsReturned()}, {self.agentInfo.numberOfTeamPlayersConnected=}")
                        tmp += 1
                    except BlockingIOError:
                        self.receive_from_server = None

                    self.retrieveClientNumber(self.receive_from_server)
                    self.disconnect_from_server(self.receive_from_server)
                    if self.firstConnexionToServer() == True:
                        continue

                    if self.firstConnexion == False and tmp >= 2:
                        if self.agentInfo.getCommandsReturned()[0] != None and self.receive_from_server == None: # If the server sends nothing, continue
                            continue
                        self.agentAlgo.setReturnCommandAnswer(self.receive_from_server)
                        self.agentAlgo.ConnectNbrManagement()
                        self.agentAlgo.forkManagement()
                        self.agentAlgo.play(self.receive_from_server)
                        self.agentAlgo.clearReturnCommand()
                        self.agentAlgo.send_to_server()
                except Exception as e:
                    print(f"Error loop: {e}")
                    continue
        except Exception as e:
            print(f"Error: {e}")

    def disconnect_from_server(self, data: str):
        """Disconnect from the server"""
        if data == "dead\n": # If the server sends "ko\n" or "dead\n", close the connection
            self.client.close()
            exit(0)

    def firstConnexionToServer(self) -> bool:
        """First connexion to the server"""
        if self.receive_from_server == "WELCOME\n": # If the server sends "WELCOME\n", send the team name
            self.client.send(f"{self.team_name}\n".encode())
            self.firstConnexion = False
            self.receive_from_server = None
            return True
        return False