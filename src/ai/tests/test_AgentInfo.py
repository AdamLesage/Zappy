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
from data_encryption import *

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

    def test06_testCommandManagement(self):
        """Test the command management"""
        data = "Hello World"
        agent_info = AgentInfo()
        agent_info.addCommandsToSend(data)
        self.assertEqual(agent_info.getCommandsToSend()[0], data)
    
    def test07_testCommandReturnedManagement(self):
        """Test the command returned management"""
        data = "Hello World"
        agent_info = AgentInfo()
        agent_info.addCommandsReturned(data)
        self.assertEqual(agent_info.getCommandsReturned()[0], data)
    
    def test08_inventoryAllCase(self):
        """Test the inventory all case"""
        agent_info = AgentInfo()
        self.assertEqual(agent_info.getInventory("all"), [["food", 0], ["linemate", 0], ["deraumere", 0],
                        ["sibur", 0], ["mendiane", 0], ["phiras", 0], ["thystame", 0]])
    
    def test09_setStatus(self):
        """Test the set status method"""
        agent_info = AgentInfo()
        agent_info.setStatus("Dead")
        self.assertEqual(agent_info.getAgentStatus(), "Dead")

    def test10_setStatus(self):
        """Test the set status method"""
        agent_info = AgentInfo()
        with self.assertRaises(ValueError):
            agent_info.setStatus("Not a status")


class DataEncryption(unittest.TestCase):
    def testDataEncryption(self):
        """Test the data encryption methods"""
        data = "Hello World"
        key = "key"
        team_name = "team"
        encrypted_data = encrypt_data(data, key, team_name)
        decrypted_data = decrypt_data(encrypted_data, key)
        self.assertEqual(decrypted_data, f"{team_name}/{data}")
        return

    def testSignatureEncryption(self):
        """Test the signature encryption methods"""
        data = "Hello World"
        key = "key"
        team_name = "team"
        encrypted_data = encrypt_data(data, key, team_name)
        decrypted_data = decrypt_data(encrypted_data, key)
        self.assertEqual(decrypted_data.split("/")[0], team_name)
        return
    
    def testMessageEncryption(self):
        """Test the message encryption methods"""
        data = "Hello World"
        key = "key"
        team_name = "team"
        encrypted_data = encrypt_data(data, key, team_name)
        decrypted_data = decrypt_data(encrypted_data, key)
        self.assertEqual(decrypted_data.split("/")[1], data)


# if __name__ == '__main__':
#     unittest.main()
