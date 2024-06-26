##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentAlert
##

from models.AgentInfo import AgentInfo
from models.AgentMoves import Moves

class AgentAlerts(AgentInfo):
    """AgentAlerts class for the Zappy project"""
    def __init__(self, agent_info: AgentInfo, minTU: int = 252):
        self.agent = agent_info
        self.alerts = []
        self.moves = Moves()
        self.minTimeU = 10 * 126
        self.formerAlert = None
        pass

    def setFoodAlert(self, minTimeU: int) -> None:
        self.minTimeU = minTimeU
    
    def setAgentInfo(self, agentInfo: AgentInfo) -> None:
        self.agent =  agentInfo
    
    def getFoodAlert(self) -> int:
        return self.minTimeU

    def checkAlerts(self) -> list[str]:
        """
        Reterns a list of alerts.
        Example: ["food", "incantation"]
        """
        playerLevel = self.agent.getLevel()
        minTimeUnitStartIncantation = 10 * 126
        
        if self.agent.getTimeUnits() <= self.minTimeU:
            """Need to eat"""
            self.alerts.clear()
            self.alerts.append("food")
            self.formerAlert = "food"
            return (self.alerts)
            # send broadcast with crypted data
        
        if playerLevel == 1 and self.agent.getInventory("linemate") >= 1 and self.agent.getTimeUnits() >= minTimeUnitStartIncantation and self.alerts.count("incantationNeeded_2") == 0 and self.formerAlert != "incantationNeeded_2":
            """Incantation lvl 1 -> 2 needed"""
            self.alerts.append("incantationNeeded_2")
            self.formerAlert = "incantationNeeded_2"
            # send broadcast with crypted data
        
        if (playerLevel == 2 and self.agent.getInventory("linemate") >= 1 and self.agent.getTimeUnits() >= minTimeUnitStartIncantation and self.alerts.count("incantationNeeded_3") == 0 and self.formerAlert != "incantationNeeded_3" and
            self.agent.getInventory("deraumere") >= 1 and
            self.agent.getInventory("sibur") >= 1):
                """Incantation lvl 2 -> 3 needed"""
                self.alerts.append("incantationNeeded_3")
                self.formerAlert = "incantationNeeded_3"
                # send broadcast with crypted data
        
        if (playerLevel == 3 and self.agent.getInventory("linemate") >= 2 and self.agent.getTimeUnits() >= minTimeUnitStartIncantation and self.alerts.count("incantationNeeded_4") == 0 and self.formerAlert != "incantationNeeded_4" and
            self.agent.getInventory("sibur") >= 1 and
            self.agent.getInventory("phiras") >= 2):
                """Incantation lvl 3 -> 4 needed"""
                self.alerts.append("incantationNeeded_4")
                self.formerAlert = "incantationNeeded_4"
                # send broadcast with crypted data
        
        if (playerLevel == 4 and self.agent.getInventory("linemate") >= 1 and self.agent.getTimeUnits() >= minTimeUnitStartIncantation and self.alerts.count("incantationNeeded_5") == 0 and self.formerAlert != "incantationNeeded_5" and
            self.agent.getInventory("deraumere") >= 1 and 
            self.agent.getInventory("sibur") >= 2 and 
            self.agent.getInventory("phiras") >= 1):
                """Incantation lvl 4 -> 5 needed"""
                self.alerts.append("incantationNeeded_5")
                self.formerAlert = "incantationNeeded_5"
                # send broadcast with crypted data
            
        if (playerLevel == 5 and self.agent.getInventory("linemate") >= 1 and self.agent.getTimeUnits() >= minTimeUnitStartIncantation and self.alerts.count("incantationNeeded_6") == 0 and self.formerAlert != "incantationNeeded_6" and
            self.agent.getInventory("deraumere") >= 2 and
            self.agent.getInventory("sibur") >= 1 and
            self.agent.getInventory("mendiane") >= 3):
                """Incantation lvl 5 -> 6 needed"""
                self.alerts.append("incantationNeeded_6")
                self.formerAlert = "incantationNeeded_6"
                # send broadcast with crypted data
        
        if (playerLevel == 6 and self.agent.getInventory("linemate") >= 1 and self.agent.getTimeUnits() >= minTimeUnitStartIncantation and self.alerts.count("incantationNeeded_7") == 0 and self.formerAlert != "incantationNeeded_7" and
            self.agent.getInventory("deraumere") >= 2 and
            self.agent.getInventory("sibur") >= 3 and
            self.agent.getInventory("phiras") >= 1):
                """Incantation lvl 6 -> 7 needed"""
                self.alerts.append("incantationNeeded_7")
                self.formerAlert = "incantationNeeded_7"
                # send broadcast with crypted data
        
        if (playerLevel == 7 and self.agent.getInventory("linemate") >= 2 and self.agent.getTimeUnits() >= minTimeUnitStartIncantation and self.alerts.count("incantationNeeded_8") == 0 and self.formerAlert != "incantationNeeded_8" and
            self.agent.getInventory("deraumere") >= 2 and
            self.agent.getInventory("sibur") >= 2 and
            self.agent.getInventory("mendiane") >= 2 and
            self.agent.getInventory("phiras") >= 2 and
            self.agent.getInventory("thystame") >= 1):
                """Incantation lvl 7 -> 8 needed"""
                self.alerts.append("incantationNeeded_8")
                self.formerAlert = "incantationNeeded_8"
                # send broadcast with crypted data
        return (self.alerts)
    
    def clearAlerts(self) -> None:
        """Clear the alerts"""
        self.alerts.clear()

#need to add more alerts
