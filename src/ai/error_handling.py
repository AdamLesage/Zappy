##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## error_handling
##

from sys import argv

# USAGE: ./zappy_ai -p port -n name -h machine

def error_handling() -> None:
    """Handle errors and throw exceptions if necessary"""
    if len(argv) != 5 and len(argv) != 7:
        raise ValueError("Invalid number of arguments")
    # If argv do not contain -p, -n
    if "-p" not in argv or "-n" not in argv:
        raise ValueError("Invalid arguments")
    # If -p is not followed by a number
    if not argv[argv.index("-p") + 1].isdigit():
        raise ValueError("Invalid port")
    # If -n is not followed by a string
    if len(argv[argv.index("-n") + 1]) == 0:
        raise ValueError("Invalid team name")
    if "-h" in argv:
        # If -h is not followed by a string
        if len(argv[argv.index("-h") + 1]) == 0:
            raise ValueError("Invalid machine name")

def retrieve_attributes() -> tuple:
    """Retrieve attributes from argv"""
    port = int(argv[argv.index("-p") + 1])
    team_name = argv[argv.index("-n") + 1]
    ip = "localhost"
    if "-h" in argv:
        ip = argv[argv.index("-h") + 1]
    return port, team_name, ip
