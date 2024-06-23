# Zappy Project User Documentation

## Overview
Zappy is a network-based multiplayer game where several teams compete on a tile map containing resources. The objective is for a team to have at least six players reach the maximum elevation level. This document provides a comprehensive guide to understand and use the Zappy project components.

### Components
1. **Server** (`zappy_server`): Handles the game logic and communication.
2. **GUI** (`zappy_gui`): Provides a graphical representation of the game.
3. **AI** (`zappy_ai`): Autonomous clients that control player actions.

### Compilation
To compile the project, the Makefile includes rules for each component:
- `zappy_server`
- `zappy_gui`
- `zappy_ai`

Run the following command to compile:
```sh
make
```

## Game Mechanics

### Elevation Ritual
Players aim to elevate within the Trantorian hierarchy. The elevation ritual requires:
- A specific number of stones.
- A specific number of players at the same level on the same tile.

**Elevation Requirements:**
| Level | Players | Linemate | Deraumere | Sibur | Mendiane | Phiras | Thystame |
|-------|---------|----------|-----------|-------|----------|--------|----------|
| 1 -> 2 | 1       | 1        | 0         | 0     | 0        | 0      | 0        |
| 2 -> 3 | 2       | 1        | 1         | 1     | 0        | 0      | 0        |
| 3 -> 4 | 2       | 2        | 0         | 1     | 0        | 2      | 0        |
| 4 -> 5 | 4       | 1        | 1         | 2     | 0        | 1      | 0        |
| 5 -> 6 | 4       | 1        | 2         | 1     | 3        | 0      | 0        |
| 6 -> 7 | 6       | 1        | 2         | 3     | 0        | 1      | 0        |
| 7 -> 8 | 6       | 2        | 2         | 2     | 2        | 2      | 1        |

### Vision
Player vision increases with each level, expanding the visible area around them. The `look` command provides the current view:
```sh
look
[player, object-on-tile1, ..., object-on-tileP, ...]
```

### Server Operation
The server runs as a single process and uses `select` for socket multiplexing. The team name `GRAPHIC` is reserved for GUI authentication.

### AI Client
The AI client is autonomous and communicates with the server via TCP sockets. The AI operates a player (drone) in the game, sending commands without waiting for responses. The server buffers requests and processes them sequentially.

### Commands
Commands follow a specific syntax and have defined execution times:
| Action        | Command       | Time (units) | Response               |
|---------------|---------------|--------------|------------------------|
| Move forward  | Forward       | 7/f          | ok                     |
| Turn right    | Right         | 7/f          | ok                     |
| Turn left     | Left          | 7/f          | ok                     |
| Look around   | Look          | 7/f          | [tile1, tile2, ...]    |
| Inventory     | Inventory     | 1/f          | [linemate n, ...]      |
| Broadcast     | Broadcast text| 7/f          | ok                     |
| Connect slots | Connect_nbr   | -            | value                  |
| Fork player   | Fork          | 42/f         | ok                     |
| Eject players | Eject         | 7/f          | ok/ko                  |
| Take object   | Take object   | 7/f          | ok/ko                  |
| Set object    | Set object    | 7/f          | ok/ko                  |
| Incantation   | Incantation   | 300/f        | Elevation underway/k   |

### Client-Server Communication
The communication protocol between AI clients and the server involves TCP sockets. The client connects using the following steps:
1. Open a socket on the server's port.
2. Exchange messages:
    ```sh
    <-- WELCOME \n
    --> TEAM-NAME \n
    <-- CLIENT-NUM \n
    <-- X Y \n
    ```

### Time Management
The execution time for actions is calculated as `action/f`, where `f` is the time unit's inverse. By default, `f=100`.

### Broadcasting
Clients can broadcast messages:
```sh
Broadcast text \n
```
The server replies to all clients with:
```sh
message K, text \n
```
Where `K` is the direction of the source.

### Ejection
A player can eject others from a tile:
```sh
eject: K \n
```
Where `K` indicates the direction from which players are ejected.

## Graphical User Interface
The GUI offers a visual representation of the game world. It uses SFML for 2D rendering and handles incoming/outgoing data with buffering.

### Starting the GUI
The GUI authenticates with the server by sending `GRAPHIC` during the team name prompt.

### GUI Features
- 2D Visualization of the game world.
- Icon-based representation of players and objects.

## Conclusion
Zappy is a challenging and engaging network game that combines strategic planning with real-time decision-making. This documentation provides the necessary details to compile, run, and understand the game's mechanics and protocols.

## References
For further information and troubleshooting, please refer to the provided protocol documentation.

---

This user documentation is intended to help you get started with the Zappy project. For any issues or questions, please refer to the project guidelines and seek support from the project maintainers.

**Happy Gaming!**

---

To download the PDF version of this documentation, please click [here](#).