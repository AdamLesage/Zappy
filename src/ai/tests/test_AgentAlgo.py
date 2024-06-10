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
