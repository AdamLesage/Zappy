##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## main_tester
##

# Python imports
import sys
sys.path.append('..')
import unittest
from unittest.mock import patch
import importlib.util

# test imports
from tests.test_Agent import TestAgent
from tests.test_AgentInfo import *
from tests.test_Commands import *
from tests.test_AgentAction import *
from tests.test_Moves import *

if __name__ == "__main__":
    unittest.main()