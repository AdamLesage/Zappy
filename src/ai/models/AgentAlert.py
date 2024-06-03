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
        if self.agent.noLifeUnits():
            """No more life units"""
            self.alerts.append("dead")
            return (self.alerts)

        if self.agent.getLifeUnits() < self.foodMin:
            """Need to eat"""
            self.alerts.append("food")
        
        if self.agent.getAgentStatus() == "Incantation":
            """Incantation in progress"""
            self.alerts.append("incantation")
        return (self.alerts)

#need to add more alerts
