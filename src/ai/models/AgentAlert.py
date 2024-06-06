##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentAlert
##

from models.AgentInfo import AgentInfo

class AgentAlerts(AgentInfo):
    """AgentAlerts class for the Zappy project"""
    def __init__(self, agent_info: AgentInfo, food: int = 100):
        self.agent = agent_info
        self.alerts = []
        self.foodMin = food
        pass

    def checkAlerts(self) -> list[str]:
        """
        Reterns a list of alerts.
        Example: ["dead", "food", "incantation"]
        """
        playerLevel = self.agent.getLevel()
        
        if self.agent.getTimeUnits() < self.foodMin:
            """Need to eat"""
            self.alerts.append("food")
            # send broadcast with crypted data
        
        if self.agent.getAgentStatus() == "Incantation":
            """Incantation in progress"""
            self.alerts.append("incantation")
            # send broadcast with crypted data
        
        if playerLevel == 1 and self.agent.getInventory("linemate") >= 1:
            """Incantation lvl 1 -> 2 needed"""
            self.alerts.append("incantationNeeded_2")
            # send broadcast with crypted data
        
        if (playerLevel == 2 and self.agent.getInventory("linemate") >= 1 and
            self.agent.getInventory("deraumere") >= 1 and
            self.agent.getInventory("sibur") >= 1):
                """Incantation lvl 2 -> 3 needed"""
                self.alerts.append("incantationNeeded_3")
                # send broadcast with crypted data
        
        if (playerLevel == 3 and self.agent.getInventory("linemate") >= 2 and
            self.agent.getInventory("sibur") >= 1 and 
            self.agent.getInventory("phiras") >= 2):
                """Incantation lvl 3 -> 4 needed"""
                self.alerts.append("incantationNeeded_4")
                # send broadcast with crypted data
        
        if (playerLevel == 4 and self.agent.getInventory("linemate") >= 1 and
            self.agent.getInventory("deraumere") >= 1 and 
            self.agent.getInventory("sibur") >= 2 and 
            self.agent.getInventory("phiras") >= 1):
                """Incantation lvl 4 -> 5 needed"""
                self.alerts.append("incantationNeeded_5")
                # send broadcast with crypted data
            
        if (playerLevel == 5 and self.agent.getInventory("linemate") >= 1 and
            self.agent.getInventory("deraumere") >= 2 and
            self.agent.getInventory("sibur") >= 1 and
            self.agent.getInventory("mendiane") >= 3):
                """Incantation lvl 5 -> 6 needed"""
                self.alerts.append("incantationNeeded_6")
                # send broadcast with crypted data
        
        if (playerLevel == 6 and self.agent.getInventory("linemate") >= 1 and
            self.agent.getInventory("deraumere") >= 2 and
            self.agent.getInventory("sibur") >= 3 and
            self.agent.getInventory("phiras") >= 1):
                """Incantation lvl 6 -> 7 needed"""
                self.alerts.append("incantationNeeded_7")
                # send broadcast with crypted data
        
        if (playerLevel == 7 and self.agent.getInventory("linemate") >= 2 and
            self.agent.getInventory("deraumere") >= 2 and
            self.agent.getInventory("sibur") >= 2 and
            self.agent.getInventory("mendiane") >= 2 and
            self.agent.getInventory("phiras") >= 2 and
            self.agent.getInventory("thystame") >= 1):
                """Incantation lvl 7 -> 8 needed"""
                self.alerts.append("incantationNeeded_8")
                # send broadcast with crypted data
        return (self.alerts)
    
    def clearAlerts(self) -> None:
        """Clear the alerts"""
        self.alerts.clear()

#need to add more alerts