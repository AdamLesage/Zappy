##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Test the AgentInfo class
##

# Python imports
import sys
sys.path.append('..')
import unittest
from unittest.mock import patch
import importlib.util

# Project imports
from models.AgentInfo import AgentInfo

class TestAgentInfo(unittest.TestCase):
    def test01_getInventory(self):
        """Test the getInventory method of the AgentInfo class"""
        testBot = AgentInfo()
        testBot.addInventory("food", 1)
        self.assertEqual(testBot.getInventory("food"), 1)
        return
    
    def test02_getInventory(self):
        """Test the getInventory method of the AgentInfo class"""
        testBot = AgentInfo()
        testBot.addInventory("food", 10)
        self.assertEqual(testBot.getInventory("food"), 10)
        return
    
    def test03_getInventory(self):
        """Test the getInventory method of the AgentInfo class"""
        testBot = AgentInfo()
        testBot.addInventory("mendiane", 10)
        testBot.addInventory("mendiane", -2)
        self.assertEqual(testBot.getInventory("mendiane"), 8)
        return
    
    def test04_getInventory(self):
        """Test the getInventory method of the AgentInfo class"""
        testBot = AgentInfo()
        testBot.addInventory("sibur", 5)
        testBot.addInventory("mendiane", 1)
        testBot.addInventory("sibur", 2)
        self.assertEqual(testBot.getInventory("sibur"), 7)
        return
    
    def test05_getInventory(self):
        """Test the getInventory method of the AgentInfo class"""
        testBot = AgentInfo()
        self.assertEqual(testBot.getInventory("linemate"), 0)
        return

if __name__ == '__main__':
    unittest.main()
