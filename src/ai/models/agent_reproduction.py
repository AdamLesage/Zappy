##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## agent_reproduction
##

import os

class AgentReproductionMixin:
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
        self.hasAskedPlayerConnected = True

    def ConnectNbrManagement(self) -> None:
        """
        Manage the Connect_nbr command
        Create a fork if there is no available slots
        """
        try:
            if self.agentInfo.commandsReturned[0] != "Connect_nbr\n":
                # There is no Connect_nbr command to manage or response has not been received
                return
            if self.agentInfo.commandsReturned[1] == None:
                # If the response has not been received
                return
            number_received = self.agentInfo.commandsReturned[1].replace("\n", "")
            if number_received.isdigit() == False:
                # If the response is not a digit
                return
            if int(number_received) < 1:
                # If there is no available slots
                print(f"Create a child process")
                self.agentInfo.commandsToSend.append("Fork\n")
            elif int(number_received) > 1:
                self.createChild()
        except Exception as e:
            print(f"Error from ConnectNbrManagement: {e}")
            return

    def forkManagement(self) -> None:
        """
        Manage the fork command
        Create a child process
        """
        try:
            if self.agentInfo.commandsReturned[0] != "Fork\n" or self.agentInfo.commandsReturned[1] == None:
                # There is no Fork command to manage or response has not been received
                return
            if self.agentInfo.commandsReturned[1].startswith("ok") == False:
                # If the response is not "ok"
                return
            print(f"Fork response: {self.agentInfo.commandsReturned[1]}")
            self.createChild()
        except Exception as e:
            print(f"Error from forkManagement: {e}")
            return

    def createChild(self) -> None:
        pid = os.fork()
        if pid > 0:
            # print(f"Parent process: {os.getpid()}") # Parent process
            pass # Maybe add fork command
        else:
            os.execvp("./zappy_ai", ["./zappy_ai", "-p", str(self.port), "-n", self.teamName, "-h", self.ip])
            # pass
            # print(f"Child process: {os.getpid()}")
