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
                print("No available slots for the team")
                exit(1)

    def manageConnectNbr(self, tmp: int) -> None:
        """
        Manage the Connect_nbr command
        retrieve number of team player
        calculate each 10 rounds the number of team player connected for incantations
        """
        if self.agentInfo.getCommandsReturned()[0] == "Connect_nbr\n" and self.receive_from_server != None and tmp < 10:
            # retrieve number of team player
            self.agentInfo.numberMaxOfTeamPlayers = int(self.receive_from_server.split('\n')[0]) + 1
        if self.agentInfo.getCommandsReturned()[0] == "Connect_nbr\n" and self.receive_from_server != None and tmp >= 10:
            self.agentInfo.availableSlots = self.agentInfo.numberMaxOfTeamPlayers - self.agentInfo.numberOfTeamPlayersConnected


    def connect_to_server(self) -> None:
        """Connect to the server from the given ip and port"""
        try:
            firstConnexion = True
            tmp = 0
            self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client.connect((self.ip, self.port))
            self.agentAlgo = AgentAlgo(self.agentInfo, 1260, self.client, self.ip, self.port, self.team_name)
            while True:
                self.client.setblocking(0)
                try:
                    self.receive_from_server = self.client.recv(1024).decode()
                    self.agentAlgo.broadcastManagement(self.receive_from_server)
                    # print(f"tmp {tmp} | {self.receive_from_server} after send {self.agentInfo.getCommandsReturned()}, {self.agentInfo.numberOfTeamPlayersConnected=}")
                    tmp += 1
                except BlockingIOError:
                    self.receive_from_server = None
                if self.disconnect_from_server(self.receive_from_server):
                    break
                if self.receive_from_server == "WELCOME\n": # If the server sends "WELCOME\n", send the team name
                    self.client.send(f"{self.team_name}\n".encode())
                    firstConnexion = False
                    self.receive_from_server = None
                    continue
                # self.retrieveClientNumber(self.receive_from_server)
                # self.retrieveWorldDimensions(self.receive_from_server)
                if firstConnexion == False and tmp >= 2:
                    if self.receive_from_server == "dead\n":
                        os.wait()
                        break
                    self.manageConnectNbr(tmp)
                    if self.agentInfo.getCommandsReturned()[0] != None and self.receive_from_server == None:
                        continue
                    self.agentAlgo.setReturnCommandAnswer(self.receive_from_server)
                    self.agentAlgo.play(self.receive_from_server)
                    self.agentAlgo.clearReturnCommand()
                    self.agentAlgo.send_to_server()
        except Exception as e:
            print(f"Error: {e}")
            exit(84)

    def disconnect_from_server(self, data: str) -> bool:
        """Disconnect from the server"""
        if data == "dead\n": # If the server sends "ko\n" or "dead\n", close the connection
            self.client.close()
            return True
        return False
