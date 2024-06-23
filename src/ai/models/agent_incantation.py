##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## agent_incantation
##

class AgentIncantationMixin:
    def launchIncantation(self) -> None:
        """
        Launch the incantation
        """
        print(f"Ask incantation | level {self.agentInfo.getLevel()}")
        if self.status != "Preparing incantation":
            return

        if self.playerOnSameTileForIncantation >= self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]: # If there is enough agent to evolve
            if self.agentInfo.getLevel() != 1:
                print(f"Enough players to evolve to level {self.agentInfo.getLevel() + 1}")
            self.status = "Incantation"
            self.agentInfo.commandsToSend.clear()
            self.agentInfo.commandsToSend.append("Incantation\n")
            if self.agentInfo.getLevel() != 1:
                self.agentInfo.commandsToSend.append("Broadcast Incantation_finished\n")
            self.playerOnSameTileForIncantation = 1


    def incantationManagement(self) -> None:
        """
        Manage the incantation of the agent
        """
        if self.status != "Incantation" and self.status != "Ask incantation" and self.status != "Going to incantation" and self.status != "Waiting player to start incantation" and self.status != "Preparing incantation" and self.status != "Can start incantation":
            # Status is not incantation
            return

        if self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("Current level:"): # If the incantation is a success
            self.hasAskedIncantation = False
            self.status = "Food"
            # level_to_set = int(self.getReturnCommand()[1].split(" ")[-1])
            # print(f"Current level [{self.getReturnCommand()[1]}] | level to set {level_to_set}")
            # self.agentInfo.setLevel(self.agentInfo.getLevel() + 1) # TODO: does not work
            if self.agentInfo.commandsToSend.count("Look\n") < 2:
                self.agentInfo.commandsToSend.append("Look\n")
            self.agentInfo.incantationResponses = 1
            self.agentInfo.commandsToSend.append("Connect_nbr\n")
            self.hasAcceptedIncantation = False

        elif self.getReturnCommand()[1] != None and self.getReturnCommand()[1].startswith("ko"): # If the incantation is a failure
            self.hasAskedIncantation = False
            self.hasAcceptedIncantation = False
            self.agentInfo.incantationResponses = 1
            self.status = "Food"
            # print(f"Player level {self.agentInfo.getLevel()} has failed incantation with status {self.status}")

    def acceptOrRefuseIncantation(self) -> None:
        """
        Accept or refuse the incantation, enter in this function only after receiving a broadcast
        """
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return
        if self.hasAcceptedIncantation == True: # If the agent has already accepted the incantation
            return
        try:
            if self.agentInfo.broadcast_received.startswith(f"need_incantation_level_{self.agentInfo.getLevel()}"): # If the agent receives a broadcast from another player asking for incantation
                if self.agentInfo.inventory["food"] >= 10:
                    #self.agentInfo.movements.clear()
                    #self.agentInfo.commandsToSend.clear()
                    self.agentInfo.commandsToSend.append(f"Broadcast accept_incantation_level_{self.agentInfo.getLevel()}\n")
                    self.hasAcceptedIncantation = True
                    self.status = "Going to incantation"
                    self.hasAskedIncantation = False
                    print(f"Accept incantation level {self.agentInfo.getLevel()} | current level: {self.agentInfo.level} | {self.agentInfo.inventory['food']=} | {self.hasAskedIncantation=} | {self.agentInfo.client_num=}")
                else:
                    print(f"Refuse incantation level {self.agentInfo.getLevel()} | current level: {self.agentInfo.level} | {self.agentInfo.inventory['food']=} | {self.hasAskedIncantation=} | {self.agentInfo.client_num=}")
                    self.status = "Food"
        except Exception as e:
            print(f"Error from acceptOrRefuseIncantation accept incantation: {e}")
            return

        try:
            # If the agent receives a broadcast to wait for incantation
            if self.hasAskedIncantation and self.agentInfo.incantationResponses < self.agentInfo.numberToEvolve[f"level{self.agentInfo.getLevel() + 1}"]:
                # If the agent has asked for incantation and has not enough responses
                self.isWaitingForResponses = True
                # print(f"Broadcast received: [{self.agentInfo.broadcast_received}], waiting: [accept_incantation_level_{str(self.agentInfo.getLevel())}], {self.agentInfo.incantationResponses=}")
                if self.agentInfo.broadcast_received.startswith(f"accept_incantation_level_{self.agentInfo.getLevel()}"):
                    self.agentInfo.incantationResponses += 1
        except Exception as e:
            print(f"Error from acceptOrRefuseIncantation count accept: {e}")
            return

    def playerOnSameTile(self) -> None:
        if self.agentInfo.getLevel() == 1: # Player level 1 do not need to wait for responses
            return
        try:
            if self.agentInfo.broadcast_received.startswith("on_same_tile"):
                print(f"A player on same tile than incanter")
                self.playerOnSameTileForIncantation += 1
        except Exception as e:
            print(f"Error from playerOnSameTile broadcast received: {e}")
            return

        try:
            # print(f"Orientation of broadcast {self.agentInfo.broadcast_orientation} | received: {self.agentInfo.broadcast_received}")
            # If player receive broadcast orientation with message "waiting_for_incantation_level_n"
            if self.agentInfo.broadcast_orientation == "0" and self.agentInfo.broadcast_received.startswith(f"waiting_for_incantation_level_{self.agentInfo.getLevel() + 1}"):
                # Player is on the same tile as agent and has not already asked for incantation
                print(f"Orientation is 0 from broadcast {self.agentInfo.broadcast_received}")
                self.agentInfo.movements.clear()
                self.agentInfo.commandsToSend.clear()
                self.playerOnSameTileForIncantation += 1
                self.agentInfo.commandsToSend.append("Broadcast on_same_tile\n")
                self.status = "Waiting player to start incantation"
        except Exception as e:
            print(f"Error from playerOnSameTile broadcast orientation: {e}")
            return

    def setItemsForIncantation(self) -> None:
        """
        Set the items to take for the incantation
        """
        # TODO: look before setting everything to avoid to take the same item twice
        print(f"Set items for incantation | level {self.agentInfo.getLevel()}")
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
        self.status = "Preparing incantation"