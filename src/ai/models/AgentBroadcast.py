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
    def __init__(self) -> None:
        pass

    def goToBroadcast(self, orientation: str, agentInfo: AgentInfo, status: str) -> None:
        """
        Player will go to the broadcast position and add the movements to the movements list
        """
        if orientation == None or status != "Going to incantation" or len(agentInfo.movements) > 0: # Player is already going to the incantation
            return False
        if len(agentInfo.movements) > 0: # If the movements list is not empty, then return
            #print(f"MOVEMENTS: {agentInfo.movements}")
            # agentInfo.commandsToSend.clear()
            return False
        if orientation == None: # If the orientation is None, then return
            return False
        print(f"Going to incantation with orientation {orientation}")
        agentInfo.commandsToSend.clear()
        agentInfo.movements.clear()
        if orientation == "0": # Player is on the broadcast position
            print("Player is on the broadcast position")
            exit(0)
            agentInfo.posIs0 = True
            return True
        elif orientation == "1": # Broadcast position is on the north of the player
            print(f"Orientation is 1, moving forward")
            agentInfo.movements.append("Forward\n")
        elif orientation == "2": # Broadcast position is on north-west of the player
            print(f"Orientation is 2, moving forward")
            agentInfo.movements.append("Forward\n")
        elif orientation == "3": # Broadcast position is on the west of the player
            print(f"Orientation is 3, moving left")
            agentInfo.movements.append("Left\n")
        elif orientation == "4": # Broadcast position is on the south-west of the player
            print(f"Orientation is 4, moving left")
            agentInfo.movements.append("Left\n")
        elif orientation == "5": # Broadcast position is on the south of the player
            print(f"Orientation is 5, moving left")
            agentInfo.movements.append("Left\n")
        elif orientation == "6": # Broadcast position is on the south-east of the player
            print(f"Orientation is 6, moving right")
            agentInfo.movements.append("Right\n")
        elif orientation == "7": # Broadcast position is on the east of the player
            print(f"Orientation is 7, moving right")
            agentInfo.movements.append("Right\n")
        elif orientation == "8": # Broadcast position is on the north-east of the player
            print(f"Orientation is 8, moving Forward")
            agentInfo.movements.append("Forward\n")
        # print(f"Moves after goToBroadcast: {agentInfo.movements} with orientation {orientation} and status {status}")
        return True
