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

    def goToBroadcast(self, orientation: str, agentInfo: AgentInfo, status: str) -> bool:
        """
        Directs the player to the broadcast position based on the given orientation and status.
        
        Parameters:
        - orientation (str): The direction towards the broadcast position relative to the player.
        - agentInfo (AgentInfo): An object containing agent information including movements.
        - status (str): The current status of the player.
        
        Returns:
        - bool: True if the player starts moving towards the broadcast position, False otherwise.
        """
        if status != "Going to incantation":  # If the player is not moving to incantation, then return
            return False
        if agentInfo.movements:  # If the movements list is not empty, then return
            return False
        if not orientation:  # If the orientation is None or empty, then return
            return False

        print(f"Going to incantation with orientation {orientation}")
        movements_map = {
            "0": [],
            "1": ["Forward\n"],
            "2": ["Forward\n", "Left\n", "Forward\n"],
            "3": ["Left\n", "Forward\n"],
            "4": ["Left\n", "Forward\n", "Left\n", "Forward\n"],
            "5": ["Left\n", "Left\n", "Forward\n"],
            "6": ["Right\n", "Forward\n", "Right\n", "Forward\n"],
            "7": ["Right\n", "Forward\n"],
            "8": ["Forward\n", "Right\n", "Forward\n"]
        }
        movements = movements_map.get(orientation)
        if movements is not None:
            agentInfo.movements.extend(movements)
            if orientation == "0":
                print("Player is on the broadcast position")
            return True
        return False
