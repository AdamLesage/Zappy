##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentBroadcast
##

# Imports
from models.AgentAlert import AgentAlerts
from models.AgentInfo import AgentInfo
from models.AgentMoves import Moves

class AgentBroadcast():
    """
    This class is used to manage the broadcast of the agent.
    Each agent can send and receive broadcast messages.

    List of broadcast messages (demands):
    - "Incantation level : n"
    - "Count mates"
    
    List of broadcast messages (answers):
    - "I am coming"
    - "Present"
    """
    def __init__(self) -> None:
        pass

    def goToBroadcast(self, orientation: str, agentInfo: AgentInfo, status: str) -> None:
        """
        Player will go to the broadcast position and add the movements to the movements list
        """
        if orientation == None or status != "Going to incantation":
            return
        agentInfo.movements.clear()
        if orientation == "0": # Player is on the broadcast position
            return
        elif orientation == "1": # Broadcast position is on the north of the player
            agentInfo.movements.append("Forward\n")
        elif orientation == "2": # Broadcast position is on north-west of the player
            agentInfo.movements.append("Forward\n")
            agentInfo.movements.append("Left\n")
            agentInfo.movements.append("Forward\n")
        elif orientation == "3": # Broadcast position is on the west of the player
            agentInfo.movements.append("Left\n")
            agentInfo.movements.append("Forward\n")
        elif orientation == "4": # Broadcast position is on the north-west of the player
            agentInfo.movements.append("Left\n")
            agentInfo.movements.append("Forward\n")
            agentInfo.movements.append("Left\n")
            agentInfo.movements.append("Forward\n")
        elif orientation == "5": # Broadcast position is on the south of the player
            agentInfo.movements.append("Left\n")
            agentInfo.movements.append("Left\n")
            agentInfo.movements.append("Forward\n")
        elif orientation == "6": # Broadcast position is on the south-east of the player
            agentInfo.movements.append("Right\n")
            agentInfo.movements.append("Forward\n")
            agentInfo.movements.append("Right\n")
            agentInfo.movements.append("Forward\n")
        elif orientation == "7": # Broadcast position is on the east of the player
            agentInfo.movements.append("Right\n")
            agentInfo.movements.append("Forward\n")
        elif orientation == "8": # Broadcast position is on the north-east of the player
            agentInfo.movements.append("Forward\n")
            agentInfo.movements.append("Right\n")
            agentInfo.movements.append("Forward\n")

    def receiveBroadcast(agentInfo: AgentInfo, broadcastMsg: str):
        """Check the broadcast message and act accordingly"""
        return