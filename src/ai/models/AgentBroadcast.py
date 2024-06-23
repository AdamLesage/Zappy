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
            agentInfo.posIs0 = True
            agentInfo.commandsToSend.clear()
            agentInfo.movements.clear()
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


##### Functions out of the class #####


def broadcastManagement(self, data: str) -> bool:
    """
    Manage the broadcast
    Split data with ' ' ---> ["message", "K,", "text"]
    Agent can accept the incantation but need to broadcast answer
    """
    #if self.status == "Going to incantation":
    if data == None or "message" not in data:
        return False
    if self.status == "Food":
        return False
    if "empty" in data:
        self.agentInfo.broadcast_received = "empty"
        return False
    if "Incantation_finished" in data:
        self.status = "Food"
        self.hasAcceptedIncantation = False
        self.hasAskedIncantation = False
        self.isWaitingForResponses = False
        self.playerOnSameTileForIncantation = 1
        self.agentInfo.incantationResponses = 0
        self.agentInfo.broadcast_received = None
        self.agentInfo.broadcast_orientation = None
        self.agentInfo.posIs0 = False
        return False
    if "I_m_here" in data:
        self.status = "Can start incantation"
        return False
    self.broadcastReceived = data
    data = data.replace(",", "") # remove comma after K
    data = data.replace("\n", "") # remove \n at the end of the string
    try:
        self.agentInfo.broadcast_received = data.split(' ')[2]
        if self.agentInfo.broadcast_received != None and self.agentInfo.broadcast_received.startswith(f"need_incantation_level_{self.agentInfo.getLevel()}"):
            # Only retrieve orientation if the broadcast is waiting for incantation
            self.agentInfo.broadcast_orientation = data.split(' ')[1]
            print(f"Broadcast received: {self.agentInfo.broadcast_received} with orientation {self.agentInfo.broadcast_orientation}")

        self.agentInfo.commandsToSend.clear()
        self.acceptOrRefuseIncantation()
        self.playerOnSameTile()
        return True

        # print(f"Command to send {self.agentInfo.commandsToSend[-1]}")
    except Exception as e:
        print(f"Error from broadcast management: {e} from data: {data}")
        return False
