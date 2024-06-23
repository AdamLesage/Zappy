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
from models.AgentMoves import Moves

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

    def test07_updateClientStatusNoAlert(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.status, "Food")

    def test08_updateClientStatusIncantation(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.alerts.alerts.append("incantation")
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.status, "Food")

    def test09_updateClientStatusContinue(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.alerts.alerts.append("Mining")
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.status, "Food")
    
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
        moves = Moves()
        # list_items = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
        agent.inventory["linemate"] = 0
        agent.addInventory("sibur", 1)
        agent.addInventory("mendiane", 1)
        agent.addInventory("phiras", 1)
        agent.addInventory("thystame", 1)
        agentAlgo = AgentAlgo(agent, 100)
        self.assertEqual(moves.findBestItemToTake(agent, playerLevel=1, itemsInPlayerVision=["linemate", "sibur", "mendiane", "phiras", "thystame"]), "linemate")

    def test10_updateClientStatus(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.alerts.alerts.append("food")
        agentAlgo.agentMentality = "Hungry"
        agentAlgo.agentInfo.inventory["food"] = 50
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.agentMentality, "Hungry")

    def test11_updateClientStatus(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.alerts.alerts.append("food")
        agentAlgo.agentMentality = "Hungry"
        agentAlgo.agentInfo.inventory["food"] = 0
        agentAlgo.updateClientStatus()
        self.assertEqual(agentAlgo.agentMentality, "Hungry")

    def test12_playLevel1_invalid_level(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.status = "Mining"
        agentAlgo.agentInfo.setLevel(2)
        agentAlgo.clientPlayLevel1()
        agentAlgo.agentInfo.setLevel(1)
        agentAlgo.clientPlayLevel2()
        agentAlgo.clientPlayLevel3()
        agentAlgo.clientPlayLevel4()
        agentAlgo.clientPlayLevel5()
        agentAlgo.clientPlayLevel6()
        agentAlgo.clientPlayLevel7()
        agentAlgo.clientPlayLevel8()
        self.assertEqual(agentAlgo.status, "Mining")

    def test13_clientPlayLevel1(self):
        agent = AgentInfo()
        agentAlgo = AgentAlgo(agent, 100)
        agentAlgo.agentInfo.inventory["food"] = 1
        agentAlgo.status = "Food"
        agentAlgo.agentInfo.setLevel(1)
        agentAlgo.setReturnCommandAnswer("Look\n")
        agentAlgo.clientPlayLevel1()
        self.assertEqual(agentAlgo.status, "Food")
