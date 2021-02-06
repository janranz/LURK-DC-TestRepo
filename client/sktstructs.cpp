#include"headers/sktstructs.h"

struct socketInfo
{
    int sktFd;
};

//PROTOCOL STRUCTS
struct pmInfo
{
    uint8_t pType = 1;
    uint16_t msgLen;
    char recipName[32];
    char senderName[32];
}__attribute__((packed));

struct chrmInfo // changeroom
{
    uint8_t pType = 2;
    uint16_t roomNum;
}__attribute__((packed));

struct fightInfo
{
    uint8_t pType = 3;
}__attribute__((packed));

struct pvpInfo
{
    uint8_t pType = 4;
    char targetPlayer[32];
}__attribute__((packed));

struct lootInfo
{
    uint8_t pType = 5;
    char targetPlayer[32];
}__attribute__((packed));

struct startInfo
{
    uint8_t pType = 6;
}__attribute__((packed));

struct errorInfo
{
    uint8_t pType = 7;
    uint8_t errCode;
    uint16_t msgLen;
}__attribute__((packed));

struct acceptInfo
{
    uint8_t pType = 8;
    uint8_t actionType;
}__attribute__((packed));

struct roomInfo
{
    uint8_t pType = 9;
    uint16_t roomNum;
    char roomName[32];
    char roomDesc[32];
}__attribute__((packed));

struct characterInfo
{
    uint8_t pType = 10;
    char playerName[32];
    uint8_t flagBits;
    uint16_t atk;
    uint16_t def;
    int16_t hp;
    uint16_t gold;
    uint16_t currentRoomNumber;
    uint16_t playerDescLen;
}__attribute__((packed));

struct gameInfo
{
    uint8_t pType = 11;
    uint16_t initPoints;
    uint16_t gameDescLen;
}__attribute__((packed));

struct leaveInfo
{
    uint8_t pType = 12;
}__attribute__((packed));

struct connectionInfo
{
    uint8_t pType = 13;
    uint16_t roomNum;
    char roomName[32];
    uint16_t roomDescLen;
}__attribute__((packed));

struct versionInfo
{
    uint8_t pType = 14;
    uint8_t lurkMajorRev;
    uint8_t lurkMinorRev;
    uint16_t extenListSize; // ignorable
}__attribute__((packed));