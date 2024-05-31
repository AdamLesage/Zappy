##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Moves
##

class Moves():
    """Moves class for the Zappy project"""
    def __init__(self) -> None:
        """Ctor of the Moves class"""
        pass
    
    def checkItem(self, lookResult: str, searchedItem):
        """
        We pass an item (food, sibur, phiras...) to this function,
        with the string given by the look command.
        And it will return True if the item is present or false if not.
        """
        return True if searchedItem in lookResult else False
    
    def reachItemList(itemToReach: str, lookResult: str):
        """
        This function will manage movements to reach an specific item.
        It will return the list of movements/commands to reach the item.
        The movements are: Left Right and Forward
        """
        midTiles = [0, 2, 6, 12, 20, 30, 42, 56, 72]
        rightTiles = [
                        3, 7, 8, 13, 14, 15, 21, 22, 23, 24, 31, 32, 33, 34, 35,
                        43, 44, 45, 46, 47, 48, 57, 58, 59, 60, 61, 62, 63
        ]
        leftTiles = [
                        1, 4, 5, 9, 10, 11, 16, 17, 18, 19, 25, 26, 27, 28, 29, 36,
                        37, 38, 39, 40, 41, 49, 50, 51, 52, 53, 54, 55
        ]
        movements = []
        posIndice = 0
        itemPosition = 0
        pos = 0

        for item in lookResult.split(","):
            if item == itemToReach:
                break
            itemPosition += 1
        if itemPosition in midTiles:
            for i in midTiles:
                if itemPosition == i:
                    return (movements)
                movements.append("Forward")
        if itemPosition in leftTiles:
            print(itemPosition)
            while itemPosition > midTiles[pos]:
                movements.append("Forward")
                pos += 1
                posIndice = midTiles[pos]
            movements.append("Left")
            while posIndice != itemPosition:
                movements.append("Forward")
                posIndice -= 1
            return (movements)
        if itemPosition in rightTiles:
            while itemPosition > midTiles[pos + 1]:
                movements.append("Forward")
                pos += 1
                posIndice = midTiles[pos]
            movements.append("Right")
            while posIndice != itemPosition:
                movements.append("Forward")
                posIndice += 1
            return (movements)

#[player,,,thystame,,food,,,,,thystame,,,,,,]
