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
from models.AgentMoves import Moves
from models.AgentInfo import AgentInfo

class TestMovesClass(unittest.TestCase):
    def test01_checkItem(self):
        """Test the checkItem methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.checkItem("[player,,,thystame,,food,,,,,thystame,,,,,,]", "food"), True)
        return
    
    def test02_checkItem(self):
        """Test the checkItem methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.checkItem("[player,,,thystame,,food,,,,,thystame,,,,,,]", "linemate"), False)
        return
    
    def test03_checkItems(self):
        """Test the checkItems methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.checkItems("[player,,,thystame,,food,,,,,thystame,,,,,,]", ["food", "linemate"]), ["food"])
        return
    
    def test04_checkItems(self):
        """Test the checkItems methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.checkItems("[player,,,thystame,,food,,,,,thystame,,,,,,]", ["linemate", "deraumere"]), [])
        return
    
    def test05_searchItem(self):
        """Test the searchItem methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.searchItem("[player,,,thystame,,food,,,,,thystame,,,,,,]",
            "deraumere"), False)
        return

    def test06_searchItem(self):
        """Test the searchItem methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.searchItem("food", "[player,food,,thystame,,food,,,,,thystame,,,,,,]", True),
            ['Forward\n', 'Left\n', 'Forward\n', 'Take food\n'])
        return
    
    def test07_searchItem(self):
        """Test the searchItem methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.searchItem("thystame", "[player,food,,thystame,,food,,,,,thystame,,,,,,]", True),
            ['Forward\n', 'Right\n', 'Forward\n', 'Take thystame\n'])
        return
    
    def test08_reachItemList(self):
        """Test the reachItemList methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.reachItemList("food", "[player,food,,thystame,,food,,,,,thystame,,,,,,]"),
            ['Forward\n', 'Left\n', 'Forward\n', 'Take food\n'])
        return
    
    def test09_reachItemList(self):
        """Test the reachItemList methods"""
        testMoves = Moves()
        self.assertEqual(testMoves.reachItemList("thystame", "[player,food,,thystame,,food,,,,,thystame,,,,,,]"),
            ['Forward\n', 'Right\n', 'Forward\n', 'Take thystame\n'])
        return
    
    def test10_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 1, ["linemate", "deraumere", "sibur"]),
            "linemate")
        return
    
    def test11_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 2, ["linemate", "deraumere", "sibur"]),
            "linemate")
        return
    
    def test12_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 2, ["deraumere", "sibur"]),
            "deraumere")
        return
    
    def test13_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 2, ["sibur"]),
            "sibur")
        return
    
    def test14_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 3, ["linemate", "deraumere", "sibur"]),
            "linemate")
        return
    
    def test16_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 3, ["sibur"]),
            "sibur")
        return
    
    def test17_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 4, ["linemate", "deraumere", "sibur"]),
            "sibur")
        return
    
    def test18_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 4, ["deraumere", "sibur"]),
            "sibur")
        return
    
    def test19_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 4, ["sibur"]),
            "sibur")
        return
    
    def test20_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 5, ["linemate", "deraumere", "sibur"]),
            "sibur")
        return
    
    def test21_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 5, ["deraumere", "sibur"]),
            "sibur")
        return
    
    def test22_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 5, ["sibur"]),
            "sibur")
        return
    
    def test23_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 6, ["linemate", "deraumere", "sibur"]),
            "sibur")
        return
    
    def test24_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 6, ["deraumere", "sibur"]),
            "sibur")
        return
    
    def test25_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 6, ["sibur"]),
            "sibur")
        return
    
    def test26_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 7, ["linemate", "deraumere", "sibur"]),
            "sibur")
        return
    
    def test27_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 7, ["deraumere", "sibur"]),
            "sibur")
        return
    
    def test28_findBestItemToTake(self):
        """Test the findBestItemToTake methods"""
        agent = AgentInfo()
        testMoves = Moves()
        self.assertEqual(testMoves.findBestItemToTake(agent, 7, ["sibur"]),
            "sibur")
        return
