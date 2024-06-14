##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## broadcast_management
##

def broadcastManagement(self, data: str) -> None:
    """
    Manage the broadcast
    Split data with ' ' ---> [""message", "K,", "text]
    """
    if data != None and data.startswith("message"):
        data.replace(",", "") # remove comma after K
        try:
            self.agentInfo.broadcast_orientation = data.split(' ')[1]
            self.agentInfo.broadcast_received = data.split(' ')[2]
            
        except Exception as e:
            print(f"Error: {e}")