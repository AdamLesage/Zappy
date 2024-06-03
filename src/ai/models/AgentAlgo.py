##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentAlgo
##

from models.AgentAlert import AgentAlerts
from models.AgentInfo import AgentInfo

class AgentAlgo():
    """
    This class is the main class for the agent's algorithm.
    It will handle the agent's actions and decisions.
    """
    def __init__(self, agentInfo: AgentInfo, fTime: int) -> None:
        self.alerts = AgentAlerts(agentInfo, fTime)
        pass

    def play(self, agentInfo: AgentInfo, data: str) -> str:
        """
        Play the game, search for resources, level up, incantation, etc
        Return the current state of the game: Continue, End, Dead, Incantation
        """
        alerts = self.alerts.checkAlerts()

        if agentInfo.noLifeUnits() or agentInfo.noTimeUnits() or "dead" in alerts:
            return "Dead"
        if "incantation" in alerts:
            # setup the logic for incantation
            return "Incantation"
        return "Continue"
    