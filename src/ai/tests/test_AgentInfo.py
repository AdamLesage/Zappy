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



class DataEncryption(unittest.TestCase):
    def testDataEncryption(self):
        """Test the data encryption methods"""
        data = "Hello World"
        key = "key"
        encrypted_data = encrypt_data(data, key)
        decrypted_data = decrypt_data(encrypted_data, key)
        self.assertEqual(decrypted_data, data)
        return
    
    def testAddSignature(self):
        """Test the add_signature method of the data_encryption module"""
        data = "Hello World"
        team_name = "epitech"
        crypted_data = add_signature(data, team_name)
        self.assertEqual(crypted_data.split("/")[1], data)
        return
    
    def testSignatureCrypted(self):
        """Test the add_signature method of the data_encryption module"""
        data = "Hello World"
        team_name = "epitech"
        crypted_data = add_signature(data, team_name)
        self.assertEqual(crypted_data.split("/")[0], encrypt_data(team_name, team_name))
        return
    
    def testSignatureDecrypted(self):
        """Test the add_signature method of the data_encryption module"""
        data = "Hello World"
        team_name = "epitech"
        crypted_data = encrypt_data(data, team_name)
        crypted_data = add_signature(data, team_name)
        decrypted_signature = crypted_data.split("/")[0]
        self.assertEqual(decrypt_data(decrypted_signature, team_name), team_name)
        return


if __name__ == '__main__':
    unittest.main()
