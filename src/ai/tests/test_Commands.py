##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## test_Commands
##

# Python imports
import sys
sys.path.append('..')
import unittest
from unittest.mock import patch
import importlib.util

# Project imports
from command.ForkCommand import ForkCommand
from command.BroadcastCommand import BroadcastCommand
from command.IncantationCommand import IncantationCommand
from command.RightCommand import RightCommand
from command.ForwardCommand import ForwardCommand
from command.LeftCommand import LeftCommand
from command.LookCommand import LookCommand
from command.InventoryCommand import InventoryCommand
from command.ConnectCommand import ConnectCommand
from command.EjectCommand import EjectCommand
from command.TakeCommand import TakeCommand
from command.SetCommand import SetCommand

class TestCommands(unittest.TestCase):
    def test01_ForkCommand(self):
        """Test the ForkCommand class"""
        testFork = ForkCommand()
        self.assertEqual(testFork.action, "fork a player")
        self.assertEqual(testFork.command, "Fork")
        self.assertEqual(testFork.time_limit, 42)
        self.assertEqual(testFork.response, "ok")
        return
    
    def test02_BroadcastCommand(self):
        """Test the BroadcastCommand class"""
        testBroadcast = BroadcastCommand()
        self.assertEqual(testBroadcast.action, "broadcast text")
        self.assertEqual(testBroadcast.command, "Broadcast text")
        self.assertEqual(testBroadcast.time_limit, 7)
        self.assertEqual(testBroadcast.response, "ok")
        return
    
    def test03_IncantationCommand(self):
        """Test the IncantationCommand class"""
        testIncantation = IncantationCommand()
        self.assertEqual(testIncantation.action, "start incantation")
        self.assertEqual(testIncantation.command, "Incantation")
        self.assertEqual(testIncantation.time_limit, 300)
        self.assertEqual(testIncantation.response, "Elevation underway Current level: k/ko")
        return
    
    def test04_RightCommand(self):
        """Test the RightCommand class"""
        testRight = RightCommand()
        self.assertEqual(testRight.action, "turn 90° right")
        self.assertEqual(testRight.command, "Right")
        self.assertEqual(testRight.time_limit, 7)
        self.assertEqual(testRight.response, "ok")
        return
    
    def test05_ForwardCommand(self):
        """Test the ForwardCommand class"""
        testForward = ForwardCommand()
        self.assertEqual(testForward.action, "move up one tile")
        self.assertEqual(testForward.command, "Forward")
        self.assertEqual(testForward.time_limit, 7)
        self.assertEqual(testForward.response, "ok")
        return
    
    def test06_LeftCommand(self):
        """Test the LeftCommand class"""
        testLeft = LeftCommand()
        self.assertEqual(testLeft.action, "turn 90° left")
        self.assertEqual(testLeft.command, "Left")
        self.assertEqual(testLeft.time_limit, 7)
        self.assertEqual(testLeft.response, "ok")
        return
    
    def test07_LookCommand(self):
        """Test the LookCommand class"""
        testLook = LookCommand()
        self.assertEqual(testLook.action, "look around")
        self.assertEqual(testLook.command, "Look")
        self.assertEqual(testLook.time_limit, 7)
        self.assertEqual(testLook.response, "[tile1, tile2, ...]")
        return
    
    def test08_InventoryCommand(self):
        """Test the InventoryCommand class"""
        testInventory = InventoryCommand()
        self.assertEqual(testInventory.action, "inventory")
        self.assertEqual(testInventory.command, "Inventory")
        self.assertEqual(testInventory.time_limit, 1)
        self.assertEqual(testInventory.response, "[linemate n, sibur n, ...]")
        return
    
    def test09_ConnectCommand(self):
        """Test the ConnectCommand class"""
        testConnect = ConnectCommand()
        self.assertEqual(testConnect.action, "number of team unused slots")
        self.assertEqual(testConnect.command, "Connect_nbr")
        self.assertEqual(testConnect.time_limit, 0)
        self.assertEqual(testConnect.response, "value")
        return
    
    def test10_EjectCommand(self):
        """Test the EjectCommand class"""
        testEject = EjectCommand()
        self.assertEqual(testEject.action, "eject players from this tile")
        self.assertEqual(testEject.command, "Eject")
        self.assertEqual(testEject.time_limit, 7)
        self.assertEqual(testEject.response, "ok/ko")
        return
    
    def test11_TakeCommand(self):
        """Test the TakeCommand class"""
        testTake = TakeCommand()
        self.assertEqual(testTake.action, "take object")
        self.assertEqual(testTake.command, "Take object")
        self.assertEqual(testTake.time_limit, 7)
        self.assertEqual(testTake.response, "ok/ko")
        return
    
    def test12_SetCommand(self):
        """Test the SetCommand class"""
        testSet = SetCommand()
        self.assertEqual(testSet.action, "set object")
        self.assertEqual(testSet.command, "Set object")
        self.assertEqual(testSet.time_limit, 7)
        self.assertEqual(testSet.response, "ok/ko")
        return


if __name__ == '__main__':
    unittest.main()