##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## agent_gameplay
##

class AgentGameplayMixin:
    def clientPlayLevel1(self) -> None:
        """
        If the agent is level 1, do the actions for level 1
        Actions such as: search for food, search for resources, level up, etc
        """
        if self.agentInfo.getLevel() != 1 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        if self.status == "Ask incantation":
            self.setItemsForIncantation()
        else:
            self.miningMode()

    def clientPlayLevel2(self) -> None:
        """
        If the agent is level 2, do the actions for level 2
        Actions such as: search for food, search for resources, level up, etc
        """
        if self.agentInfo.getLevel() != 2 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
            return
        if self.status == "Can start incantation":
            self.setItemsForIncantation()
            return
        if self.status == "Ask incantation" or self.status == "Waiting player to start incantation":
            self.hasAskedIncantation = True
            #self.agentInfo.commandsToSend.clear()
            if len(self.agentInfo.commandsToSend) >= 2:
                return
            self.status = "Waiting player to start incantation"
            self.agentInfo.commandsToSend.append(f"Broadcast need_incantation_level_{self.agentInfo.getLevel()}\n")
            self.agentInfo.commandsToSend.append(f"Broadcast empty\n")
            print(f"Broadcast need_incantation_level_{self.agentInfo.getLevel()} | client num {self.agentInfo.client_num}")
        else:
            self.miningMode()

    def clientPlayLevel3(self) -> None:
        """
        If the agent is level 3, do the actions for level 3
        Actions such as: search for food, help agent level 1 to upgrade to level 2, level up, etc
        """
        if self.agentInfo.getLevel() != 3 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode()  # Search for food
        else:
            self.miningMode()

    def clientPlayLevel4(self) -> None:
        """
        If the agent is level 4, do the actions for level 4
        Actions such as: search for food, help agent level 2 to upgrade to level 3, level up, etc
        Once level 4 is reached, agent is considered as a "helper" agent
        Then once there is enough agents to reach level 5, he will join or start an incantation to level 5
        """
        if self.agentInfo.getLevel() != 4 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel5(self) -> None:
        """
        If the agent is level 5, do the actions for level 5
        Actions such as: search for food, help agent level 3 to upgrade to level 4, level up, etc
        """
        if self.agentInfo.getLevel() != 5 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel6(self) -> None:
        """
        If the agent is level 6, do the actions for level 6
        Actions such as: search for food, help agent level 4 and level 5 to upgrade to level 6, level up, etc
        The goal of agent level 6 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 6 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel7(self) -> None:
        """
        If the agent is level 7, do the actions for level 7
        Actions such as: search for food, help agent and level 4, level 5 and level 6 to upgrade to level 7, level up, etc
        The goal of agent level 7 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 7 or self.status == "Incantation":
            return
        if self.status == "Food":
            self.foodMode() # Search for food
        else:
            self.miningMode()

    def clientPlayLevel8(self) -> None:
        """
        If the agent is level 8, do the actions for level 8
        Actions such as: search for food, help agent and level 4, level 5, level 6 and level 7 to upgrade to level 8, level up, etc
        The goal of agent level 8 if to help other agents to level up so incantation will be easier
        """
        if self.agentInfo.getLevel() != 2 or self.status == "Incantation":
            return
        self.foodMode() # Search for food
