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
