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
