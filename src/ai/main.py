#! /usr/bin/env python3

from sys import stderr
from error_handling import error_handling

def main() -> None:
    try:
        error_handling()
    except ValueError as e:
        print(f"Error: {e}", file=stderr)
        exit(84)
    print("Hello world!")

if __name__ == "__main__":
    main()
