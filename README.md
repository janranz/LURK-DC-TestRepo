# Get your bearings straight.

## |-TODO-|

...

---

## |-Mapping-|
Lurk Protocol Version 2.2
* Variable-length text fields are sent **without** a null terminator.
* All numbers are sent little-endian.
* Except as noted (health), all integer fields are **unsigned**.

### Protocols Ordered (BYTES):
1. **MESSAGE:**
    * (1BYTE)TYPE: 1 | (2)MSG_LEN (unsigned) | (32) Recip. Name | (32) Sender Name | (?) Message
2. **CHANGEROOM:**
    * (1)TYPE: 2 | (2) Room Number
3. **FIGHT:**
    * (1)TYPE: 3
4. **PVPFIGHT:**
    * (1)TYPE: 4 | (32) Name of Target Player
5. **LOOT:**
    * (1)TYPE: 5 | (32) Name of Target Player
6. **START:**
    * (1)TYPE: 6
7. **ERROR:**
    * (1)TYPE: 7 |(1) Error Code | (2) Error Message Length | (?) Error Message
        * Codes and Meaning
            * 0 | **OTHER**: Some error not covered here.
            * 1 | **BAD_ROOM**: Inappropriate room attempt.
            * 2 | **PLAYER_EXISTS**: Attempt to create player that already exists.
            * 3 | **BAD_MONSTER**: Attempt to loot a nonexistent or not present monster.
            * 4 | **STAT_ERROR**: Attempt to set inappropriate player stats.
            * 5 | **NOT_READY**: Attempt an action too early (CHANGEROOM before START).
            * 6 | **NO_TARGET**: Attempt to interact nonexisting player.
            * 7 | **NO_FIGHT**: If requesting a fight that cannot happen for other reasons. (no monsters)
            * 8 | **NO_PVP**: Server does not have support for PVP Combat.
8. **ACCEPT:**
    * (1)TYPE: 8 | (1) Type of action accepted
9. **ROOM:**
    * (1)TYPE: 9 | (2) Room Number (same used in CHANGEROOM) | (32) Room Name | (32) Room Description Length | (?) Room Description.
10. **CHARACTER:**
    * (1)TYPE: 10 | (32) Player Name | (1) Flags: \[ALIVE/JOIN_BATTLE/MONSTER/STARTED/READY/RES./RES./RES.\] | (2) ATTACK | (2) DEFENSE | (2) REGEN | (2) HEALTH (signed) | (2) GOLD | (2) Current Room Number | (2) Description Length | (?) Player Description
        * Flag and Meaning
            * **ALIVE**: Character is Alive (1 = Alive, 0 = Not Alive)
            * **JOIN_BATTLE**: Character will automatically join battles in the room they are in (1 = Join, 2 = Do Not Join)
            * **MONSTER**: Character is a monster (1 = Monster, 0 = player)
            * **STARTED**: Character has started the game (1 = started, 0 = not started)
            * **READY**: Character is ready to start the game (1 = ready, 0 = not ready)
        * When a client uses CHARACTER to describe a new player, the server should ignore the client's initial specification for health, gold, and room. The Monster flag is used when describing monsters found in the game rather than other human players.
11. **GAME:**
    * (1)TYPE: 11 | (2) Initial Points | (2) Stat Limit | (2) Description Length | (?) Game Description
12. **LEAVE:**
    * (1)TYPE: 12
13. **CONNECTION:**
    * (1)TYPE: 13 | (2) Room Number (same room number used for CHANGEROOM) | (32) Room Name | (2) Room Description Length | (?) Room description
14. **VERSION:**
    * (1)TYPE: 14 | (1) LURK Major revision 8-bit unsigned int | (1) LURK Minor revision 8-bit unsigned int | (2) Size of the list of extensions in bytes | (?) List of extensions
        * List of extension format (Byte and Meaning):
            * (2) Length of the first extension as unsigned 16-bit int | (?) First extension
    * **Servers and clients are not required to support any extension, but must handle this protocol accordingly**

### Client-To-Server-only:
1. **CHANGEROOM** (TYPE: 2)
2. **FIGHT** (TYPE: 3)
3. **PVPFIGHT** (TYPE: 4)
4. **LOOT** (TYPE: 5)
5. **START** (TYPE: 6)
6. **LEAVE** (TYPE: 12)

### Client-And-Server:
1. **MESSAGE** (TYPE: 1)
2. **CHARACTER** (TYPE: 10)

### Server-To-Client-only:
1. **ERROR** (TYPE: 7)
2. **ACCEPT** (TYPE: 8)
3. **ROOM** (TYPE: 9)
4. **GAME** (TYPE: 11)
5. **CONNECTION** (TYPE: 13)
6. **VERSION** (TYPE: 14)

### Guaranteed-Order-of-Operations:
* **Upon initial connection to the server**:
    1. **VERSION** (TYPE: 14) \[*server*\]
    2. **GAME** (TYPE: 11) \[*server*\]
    3. **CHARACTER** (TYPE: 10) \[*client*\]
    4. **ACCEPT** (TYPE: 8) OR **ERROR** (TYPE: 7) \[*server*\] | \[*server*\]
    5. **START** (TYPE: 6) \[*client*\]
    6. **ROOM** (TYPE: 9) \[*server*\]
    7. **CONNECTION** (TYPE: 13) \[*server*\]
    8. **CHARACTER** (TYPE: 10) \[*server*\]

* **Upon player changing a room**:
    1. **CHANGEROOM** (TYPE: 2) \[*client*\]
    2. **ACCEPT** (TYPE: 8) OR **ERROR** (TYPE: 7) \[*server*\]
    3. **ROOM** (TYPE: 9) \[*server*\]
    4. **CONNECTION** (TYPE: 13) \[*server*\]
    5. **CHARACTER** (TYPE: 10) \[*server*\]

* **Upon player sending a message**:
    1. **MESSAGE** (TYPE: 1) \[*client*\]
    2. **ACCEPT** (TYPE: 8) OR **ERROR** (TYPE: 7) \[*server*\]
    3. **MESSAGE** (TYPE: 1) \[*server* (to Recipient(s))\]

* **Upon other players connecting or leaving room, loot event, fight event, PVP event**:
    1. **CHARACTER** (TYPE: 10) \[*server*\]

* **Upon player looting another player**:
    1. **LOOT** (TYPE: 5) \[*client*\]
    2. **ACCEPT** (TYPE: 8) OR **ERROR** (TYPE: 7) \[*server*\]
    3. **CHARACTER** (TYPE: 10) \[*server*\]

* **Upon player fighting monster**:
    1. **FIGHT** (TYPE: 3) \[*client*\]
    2. **ACCEPT** (TYPE: 8) OR **ERROR** (TYPE: 7) \[*server*\]
    3. **CHARACTER** (TYPE: 10) \[*server*\]

### Server-Features:

* **Global Chat Support**
* **Revive / Restart Character upon death**
* **More Loot Events**
* **Store / Merchant**

## |-Pseudo-Section-|

**Intended Language(s)**: C/C++

**Intended GUI(s)**: curses/ncurses/gtk+/Qt

**Structure**: threading/Linked-Lists/Object-Oriented

**Things to consider**:
* Slow reads/writes
* Blocking/nonblocking functions
* Race conditions
* Thread safety / mutual exclusion
* SIGs (SIGPIPE)
* Recall fight idea (health threshold from class.
* Track (own) user in separate struct
