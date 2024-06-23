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

    def splitServerResponseAndBroadcast(self, data: str) -> list[str]:
        """
        Check if the data received is a broadcast
        Return a list of two strings:
        - the first string is the response from the server for the last command sent 
        - the second string is the broadcast message
        Strings can be None if there is no response or no broadcast
        Exemple:    "message k, empty\nok\n" --> ["ok\n", "message k, empty"]
                    "ok\nmessage k, empty\n" --> ["ok\n", "message k, empty"]
                    "ok\n" --> ["ok\n", None]
                    "message k, empty\n" --> [None, "message k, empty"]
        """
        if data == None:
            return [None, None]
        listBroadcasts = ["need_incantation_level_", "accept_incantation_level_", "waiting_for_incantation_level_", "on_same_tile", "yes_we_are_on_the_map", "Anybody_on_the_map_?", "message ", "empty"]
        splited_data = data.split('\n')
        return_list = [None, None]
        if "message " in splited_data[0] and any(broadcast in splited_data[0] for broadcast in listBroadcasts):
            return_list[1] = splited_data[0]
            if len(splited_data) > 1:
                return_list[0] = splited_data[1]
            return return_list
        if "message " in splited_data[1] and any(broadcast in splited_data[1] for broadcast in listBroadcasts):
            return_list[1] = splited_data[1]
            return_list[0] = splited_data[0]
            return return_list
        if len(splited_data) == 1 and any(broadcast in splited_data[0] for broadcast in listBroadcasts):
            return_list[1] = splited_data[0]
            return return_list
        return_list[0] = data
        return return_list

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
    
    def bufferManagement(self, data: str) -> bool:
        """
        if data_received != None:
            if there is a \n in data_received and self.receive_from_server != None --> self.receive_from_server += data_received | return True because we have the full data
            elif there is a \n in data_received and self.receive_from_server == None --> self.receive_from_server = data_received | return True because we have the full data
            elif there is no \n in data_received and self.receive_from_server != None --> self.receive_from_server += data_received | return False because we don't have the full data
            elif there is no \n in data_received and self.receive_from_server == None --> self.receive_from_server = data_received | return False because we don't have the full data
        """
        if data == None or data == "":
            return False
        if "\n" in data and self.receive_from_server != None: # If there is a \n in data_received and self.receive_from_server != None
            self.receive_from_server += data
            return True
        elif "\n" in data and self.receive_from_server == None: # If there is a \n in data_received and self.receive_from_server == None
            self.receive_from_server = data
            return True
        elif "\n" not in data and self.receive_from_server != None: # If there is no \n in data_received and self.receive_from_server != None
            self.receive_from_server += data
            return False
        elif "\n" not in data and self.receive_from_server == None: # If there is no \n in data_received and self.receive_from_server == None
            self.receive_from_server = data
            return False
        return False

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
                        data_received = self.client.recv(1024).decode()

                        if self.bufferManagement(data_received) == False:
                            print(f"continue because bufferManagement")
                            continue
                        splited_response = self.splitServerResponseAndBroadcast(self.receive_from_server)
                        if self.agentAlgo.broadcastManagement(splited_response[1]) == True:
                            self.receive_from_server = None
                            print(f"continue because broadcastManagement")
                            continue
                        print("2")
                        #if self.isDataReceivedABroadcast(self.receive_from_server) == True:
                        #    self.receive_from_server = None
                        #    continue
                        print(f"tmp {tmp} | {self.receive_from_server} after send {self.agentInfo.getCommandsReturned()}")
                        print(f"tmp {tmp} | {splited_response} after send {self.agentInfo.getCommandsReturned()}")
                        tmp += 1
                    except BlockingIOError as e:
                        pass

                    self.retrieveClientNumber(self.receive_from_server)
                    self.disconnect_from_server(self.receive_from_server)
                    if self.firstConnexionToServer() == True:
                        continue

                    if self.firstConnexion == False and tmp >= 2:
                        if self.agentInfo.getCommandsReturned()[0] != None and self.receive_from_server == None: # If the server sends nothing, continue
                            continue
                        if self.receive_from_server == "Elevation underway\n":
                            continue
                        if self.receive_from_server != None:
                            if "Current level" in splited_response[0]:
                                self.agentAlgo.setStatus("Mining")
                                self.receive_from_server = None
                        self.agentAlgo.setReturnCommandAnswer(splited_response[0])
                        # print(f"Commands returned: {self.agentInfo.getCommandsReturned()}")
                        self.agentAlgo.countPassedCommands += 1
                        self.agentAlgo.ConnectNbrManagement()
                        self.agentAlgo.forkManagement()
                        self.agentAlgo.play(self.receive_from_server)
                        self.agentAlgo.clearReturnCommand()
                        self.agentAlgo.send_to_server()
                        if self.receive_from_server != None and "\n" in self.receive_from_server: # If the server sends something, clear the buffer
                            self.receive_from_server = None
                except Exception as e:
                    print(f"Error loop: {e}")
                    exit(1)
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