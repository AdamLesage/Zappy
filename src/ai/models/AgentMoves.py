##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Moves
##

from models.AgentInfo import AgentInfo
import random

class Moves():
    """Moves class for the Zappy project"""
    def __init__(self) -> None:
        """Ctor of the Moves class"""
        pass
    
    def checkItem(self, lookResult: str, searchedItem) -> bool:
        """
        We pass an item (food, sibur, phiras...) to this function,
        with the string given by the look command.
        And it will return True if the item is present or false if not.
        """
        return True if searchedItem in lookResult else False
    
    def checkItems(self, lookResult: str, searchedItems: list[str]) -> list[str]:
        """
        We pass a list of items (food, sibur, phiras...) to this function,
        with the string given by the look command.
        And it will return a list of items that are present in the look result.
        """
        presentItems = []
        for item in searchedItems:
            if self.checkItem(lookResult, item):
                presentItems.append(item)
        return presentItems
    
    def reachItemList(self, itemToReach: str, lookResult: str) -> list[str]:
        """
        This function will manage movements to reach an specific item.
        It will return the list of movements/commands to reach the item.
        The movements are: Left Right and Forward\n
        """
        midTiles = [0, 2, 6, 12, 20, 30, 42, 56, 72]
        rightTiles = [
                        3, 7, 8, 13, 14, 15, 21, 22, 23, 24, 31, 32, 33, 34, 35,
                        43, 44, 45, 46, 47, 48, 57, 58, 59, 60, 61, 62, 63, 73, 74,
                        75, 76, 77, 78, 79, 80
        ]
        leftTiles = [
                        1, 4, 5, 9, 10, 11, 16, 17, 18, 19, 25, 26, 27, 28, 29, 36,
                        37, 38, 39, 40, 41, 49, 50, 51, 52, 53, 54, 55, 64, 65, 66,
                        67, 68, 69, 70, 71
        ]
        movements = []
        posIndice = 0
        itemPosition = 0
        pos = 0

        lookResult = lookResult.replace("[ ", "")
        lookResult = lookResult.replace(" ]", "")
        lookResult = lookResult.replace("[", "")
        lookResult = lookResult.replace("]", "")
        for item in lookResult.split(","):
            if itemToReach in item:
                break
            itemPosition += 1
        if itemPosition in midTiles:
            for i in midTiles:
                if itemPosition == i:
                    movements.append(f"Take {itemToReach}\n")
                    return (movements)
                movements.append("Forward\n")
        elif itemPosition in leftTiles:
            # print(itemPosition)
            while itemPosition > midTiles[pos]:
                movements.append("Forward\n")
                pos += 1
                posIndice = midTiles[pos]
            movements.append("Left\n")
            while posIndice != itemPosition:
                movements.append("Forward\n")
                posIndice -= 1
            movements.append(f"Take {itemToReach}\n")
            return (movements)
        elif itemPosition in rightTiles:
            while itemPosition > midTiles[pos + 1]:
                movements.append("Forward\n")
                pos += 1
                posIndice = midTiles[pos]
            movements.append("Right\n")
            while posIndice != itemPosition:
                movements.append("Forward\n")
                posIndice += 1
            movements.append(f"Take {itemToReach}\n")
            return (movements)

    def searchItem(self, itemToSearch: str, lookResult: str, needReaching: bool = True):
        """
        This function will search for an item in the look result.
        If the item is present and needReaching is True,
        it will return the list of movements to reach the item.
        If the item is not present, it will return False.
        """
        if self.checkItem(lookResult, itemToSearch) and needReaching == True:
            return self.reachItemList(itemToSearch, lookResult)
        return False

    def findBestItemToTake(self, agentInfo: AgentInfo, playerLevel: int, itemsInPlayerVision: list) -> str:
        """
        Find the best item to take according to the player level
        """
        # If there are multiple items with the same quantity, choose best item for player level
        if playerLevel == 1:
            return "linemate"
        elif playerLevel == 2:
            if agentInfo.inventory["linemate"] < 2 and "linemate" in itemsInPlayerVision:
                return "linemate"
            if agentInfo.inventory["deraumere"] < 1 and "deraumere" in itemsInPlayerVision:
                return "deraumere"
            if agentInfo.inventory["sibur"] < 1 and "sibur" in itemsInPlayerVision:
                return "sibur"
            return random.choice(itemsInPlayerVision)
        elif playerLevel == 3:
            if agentInfo.inventory["phiras"] < 2 and "phiras" in itemsInPlayerVision:
                return "phiras"
            if agentInfo.inventory["linemate"] < 2 and "linemate" in itemsInPlayerVision:
                return "linemate"
            if agentInfo.inventory["sibur"] < 1 and "sibur" in itemsInPlayerVision:
                "sibur"
            return random.choice(itemsInPlayerVision)
        elif playerLevel == 4:
            if agentInfo.inventory["sibur"] < 2 and "sibur" in itemsInPlayerVision:
                return "sibur"
            if agentInfo.inventory["phiras"] < 1 and "phiras" in itemsInPlayerVision:
                return "phiras"
            if agentInfo.inventory["deraumere"] < 1 and "deraumere" in itemsInPlayerVision:
                return "deraumere"
            if agentInfo.inventory["linemate"] < 1 and "linemate" in itemsInPlayerVision:
                return "linemate"
            return random.choice(itemsInPlayerVision)
        elif playerLevel == 5:
            if agentInfo.inventory["mendiane"] < 3 and "mendiane" in itemsInPlayerVision:
                return "mendiane"
            if agentInfo.inventory["sibur"] < 1 and "sibur" in itemsInPlayerVision:
                return "sibur"
            if agentInfo.inventory["deraumere"] < 1 and "deraumere" in itemsInPlayerVision:
                return "deraumere"
            if agentInfo.inventory["linemate"] < 1 and "linemate" in itemsInPlayerVision:
                return "linemate"
            return random.choice(itemsInPlayerVision)
        elif playerLevel == 6:
            if agentInfo.inventory["sibur"] < 3 and "sibur" in itemsInPlayerVision:
                return "sibur"
            if agentInfo.inventory["phiras"] < 1 and "phiras" in itemsInPlayerVision:
                return "phiras"
            if agentInfo.inventory["deraumere"] < 2 and "deraumere" in itemsInPlayerVision:
                return "deraumere"
            if agentInfo.inventory["linemate"] < 1 and "linemate" in itemsInPlayerVision:
                return "linemate"
            return random.choice(itemsInPlayerVision)
        elif playerLevel == 7:
            if agentInfo.inventory["phiras"] < 2 and "phiras" in itemsInPlayerVision:
                return "phiras"
            if agentInfo.inventory["thystame"] < 1 and "thystame" in itemsInPlayerVision:
                return "thystame"
            if agentInfo.inventory["mendiane"] < 2 and "mendiane" in itemsInPlayerVision:
                return "mendiane"
            if agentInfo.inventory["sibur"] < 2 and "sibur" in itemsInPlayerVision:
                return "sibur"
            if agentInfo.inventory["deraumere"] < 2 and "deraumere" in itemsInPlayerVision:
                return "deraumere"
            if agentInfo.inventory["linemate"] < 1 and "linemate" in itemsInPlayerVision:
                return "linemate"
            return random.choice(itemsInPlayerVision)
        else:
            return random.choice(itemsInPlayerVision)

#[player,,,thystame,,food,,,,,thystame,,,,,,]
