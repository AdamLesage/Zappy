# IA strategy for Zappy

## Goals

Our players must:
  - reach level 8 the fastest possible.
  - stay alive
  - use incantations with other players (can be player from other teams)
  - gather resources and communicate with other players to share resources

## Strategy

### Level 1 to 8

Once a player reaches a new level, he must:
  - send broadcast message to all players to inform them of his new level, then a count will be started to wait for other players to reach the same level.


If a player picks up a resource or set a resource on a tile, he must:
  - add current ressource to team inventory (if he picks a diamond, add 1 diamond to team inventory)
  - send a broadcast message to all players to inform them of the new resource in the team inventory
  - others players on the team will update their team inventory with resources given from broadcast messages
