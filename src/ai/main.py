#! /usr/bin/env python3

from sys import stderr
from error_handling import *
from models.Agent import Agent

def main() -> None:
    try:
        error_handling()
    except ValueError as e:
        print(f"Error in main: {e}", file=stderr)
        exit(84)
    port, team_name, ip = retrieve_attributes()
    agent = Agent(port, team_name, ip)
    agent.connect_to_server()


if __name__ == "__main__":
    main()
