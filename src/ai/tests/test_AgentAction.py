##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## test_AgentAction
##

# Python imports
import sys
sys.path.append('..')
import unittest
from unittest.mock import patch
import importlib.util

# Project imports
from models.AgentInfo import AgentInfo
from models.AgentAction import AgentAction

class TestAgentAction(unittest.TestCase):
    def test01_updateInventory_invalid_item(self):
        agent_info = AgentInfo()
        agent_action = AgentAction(agent_info)
        self.assertFalse(agent_action.updateInventories(["invalid input", "add", 1]))

    def test02_updateInventory_invalid_action(self):
        agent_info = AgentInfo()
        agent_action = AgentAction(agent_info)
        self.assertFalse(agent_action.updateInventories(["food", "invalid action", 1]))

    def test03_updateInventory_add_food(self):
        agent_info = AgentInfo()
        agent_action = AgentAction(agent_info)
        agent_info.inventory = [["food", 0]]
        self.assertTrue(agent_action.updateInventories(["food", "add", 1]))
        self.assertEqual(agent_info.inventory[0][1], 1)

    def test04_updateInventory_remove_food(self):
        agent_info = AgentInfo()
        agent_action = AgentAction(agent_info)
        agent_info.inventory = [["food", 1]]
        self.assertTrue(agent_action.updateInventories(["food", "remove", 1]))
        self.assertEqual(agent_info.inventory[0][1], 0)
