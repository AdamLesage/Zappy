##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## test_Moves
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

class TestAgentAlert(unittest.TestCase):
    def test01_food_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setTimeUnits(50)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test02_incantation_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setStatus("Incantation")
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test03_incantation_lvl_1_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.addInventory("linemate", 1)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test04_incantation_lvl_2_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLevel(2)
        agent.addInventory("linemate", 1)
        agent.addInventory("deraumere", 1)
        agent.addInventory("sibur", 1)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test05_incantation_lvl_3_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLevel(3)
        agent.addInventory("linemate", 2)
        agent.addInventory("sibur", 1)
        agent.addInventory("phiras", 2)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test06_incantation_lvl_4_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLevel(4)
        agent.addInventory("linemate", 1)
        agent.addInventory("deraumere", 1)
        agent.addInventory("sibur", 2)
        agent.addInventory("phiras", 1)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test07_incantation_lvl_5_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLevel(5)
        agent.addInventory("linemate", 1)
        agent.addInventory("deraumere", 2)
        agent.addInventory("sibur", 1)
        agent.addInventory("mendiane", 3)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test08_incantation_lvl_6_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLevel(6)
        agent.addInventory("linemate", 1)
        agent.addInventory("deraumere", 2)
        agent.addInventory("sibur", 3)
        agent.addInventory("mendiane", 1)
        agent.addInventory("phiras", 3)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])
    
    def test09_incantation_lvl_7_alert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLevel(7)
        agent.addInventory("linemate", 2)
        agent.addInventory("deraumere", 2)
        agent.addInventory("sibur", 2)
        agent.addInventory("mendiane", 2)
        agent.addInventory("phiras", 2)
        agent.addInventory("thystame", 1)
        agentAlert.checkAlerts()
        self.assertEqual(agentAlert.alerts, ["food"])

    def test10_clearAlerts(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agentAlert.alerts.append("food")
        self.assertEqual(agentAlert.alerts, ["food"])
        agentAlert.clearAlerts()
        self.assertEqual(agentAlert.alerts, [])
    
    def test11_setFoodAlert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agentAlert.setFoodAlert(256)
        self.assertEqual(agentAlert.getFoodAlert(), 256)
    
    def test12_setFoodAlert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 500)
        agentAlert.setFoodAlert(100)
        self.assertEqual(agentAlert.getFoodAlert(), 100)
    
    def test13_getFoodAlert(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        self.assertEqual(agentAlert.getFoodAlert(), 1260)

    def test14_setAgentInfo(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLifeUnits(256)
        agentAlert.setAgentInfo(agent)
        self.assertEqual(agentAlert.agent, agent)
    
    def test_setAgentInfo(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLifeUnits(256)
        agent.setStatus("Incantation")
        agentAlert.setAgentInfo(agent)
        self.assertEqual(agentAlert.agent, agent)
    
    def test15_setAgentInfo(self):
        agent = AgentInfo()
        agentAlert = AgentAlerts(agent, 100)
        agent.setLifeUnits(256)
        agent.setLevel(5)
        agent.setLevel(5)
        agentAlert.setAgentInfo(agent)
        self.assertEqual(agentAlert.agent, agent)
