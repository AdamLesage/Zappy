##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## AgentInfo
##

class AgentInfo():
    """AgentInfo class for the Zappy project"""
    def __init__(self):
        """Ctor of the AgentInfo class"""
        self.commandsToSend = []
        self.commandsReturned = []
        return
    
    # Getters
    def getCommandsToSend(self):
        """Get the list of commands to send to the server"""
        return (self.commandsToSend)
    
    def getCommandsReturned(self):
        """Get the list of answer send by the server"""
        return (self.commandsReturned)
    
    # Setters
    def addCommandsToSend(self):
        return
    
    def addCommandsReturned(self):
        return
