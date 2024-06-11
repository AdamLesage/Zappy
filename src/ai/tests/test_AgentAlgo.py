##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## test_AgentAlgo
##

# Python imports
import sys
sys.path.append('..')
import unittest
from unittest.mock import patch
import importlib.util

# Project imports
from models.AgentAlert import AgentAlerts
from models.AgentInfo import AgentInfo
from models.AgentAlgo import AgentAlgo

class TestAgentAlgo(unittest.TestCase):
    def test01_setReturnCommansAnswer(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.setReturnCommandAnswer("ok")
        self.assertEqual(agentAlgo.getReturnCommand()[1], "ok")

    def test02_setReturnCommansAnswer(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.setReturnCommandAnswer("ko")
        self.assertEqual(agentAlgo.getReturnCommand()[1], "ko")
    
    def test03_clearReturnCommansAnswer(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.setReturnCommandAnswer("Look")
        agentAlgo.clearReturnCommand()
        self.assertEqual(agentAlgo.getReturnCommand()[0], None)
    
    def test04_clearReturnCommansAnswer(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.setReturnCommandAnswer("ok")
        agentAlgo.clearReturnCommand()
        self.assertEqual(agentAlgo.getReturnCommand()[1], None)

    def test05_updateClientStatus(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.alerts.alerts.append("food")
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.status, "Food")

    def test06_updateAgentInfo(self):
        agent = AgentInfo()
        agent.setLevel(1)
        agent.addInventory("linemate", 1)
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.updateAgentInfo(agent)
        self.assertEqual(agentAlgo.agentInfo.getLevel(), 1)
        self.assertEqual(agentAlgo.agentInfo.getInventory("linemate"), 1)

    def test07_updateClientStatusNoAlert(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.status, "Continue")

    def test08_updateClientStatusIncantation(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.alerts.alerts.append("incantation")
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.status, "Incantation")

    def test09_updateClientStatusContinue(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.alerts.alerts.append("Continue")
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.status, "Continue")
    
    def test05_testUpdateInventory(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.updateInventory("food 1")
        self.assertEqual(agent.getInventory("food"), 1)
    
    def test06_testUpdateInventory(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.updateInventory("linemate 2")
        self.assertEqual(agent.getInventory("linemate"), 2)
    
    def test07_testUpdateInventory(self):
        list = ["food 1, linemate 6, deraumere 3, sibur 4"]
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        for elem in list:
            agentAlgo.updateInventory(elem)
        self.assertEqual(agent.getInventory("linemate"), 6)
    
    def test08_testUpdateInventory(self):
        list = ["food 1, linemate 6, deraumere 3, sibur 4, thystame 1"]
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        for elem in list:
            agentAlgo.updateInventory(elem)
        self.assertEqual(agent.getInventory("phiras"), 0)

    def test09_findBestItemToTake(self):
        agent = AgentInfo()
        # list_items = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
        agent.inventory["linemate"] = 0
        agent.addInventory("sibur", 1)
        agent.addInventory("mendiane", 1)
        agent.addInventory("phiras", 1)
        agent.addInventory("thystame", 1)
        agentAlgo = AgentAlgo(agent, 100)
        self.assertEqual(agentAlgo.findBestItemToTake(playerLevel=1, itemsInPlayerVision=["linemate", "sibur", "mendiane", "phiras", "thystame"]), "linemate")