#pragma once
#include<cstdint>

struct socketInfo
{
    int sktFd;
};

//PROTOCOL STRUCTS (no longer storing type - redundant)
struct pmInfo
{
    uint16_t msgLen;
    char recipName[32];
    char senderName[32];
}__attribute__((packed));

struct chrmInfo // changeroom
{
    uint16_t roomNum;
}__attribute__((packed));

// struct fightInfo
// {
//     const uint8_t pType = 3;
// }__attribute__((packed));

struct pvpInfo
{
    char targetPlayer[32];
}__attribute__((packed));

struct lootInfo
{
    char targetPlayer[32];
}__attribute__((packed));

// struct startInfo
// {
//     const uint8_t pType = 6;
// }__attribute__((packed));

struct errorInfo
{
    uint8_t errCode;
    uint16_t msgLen;
}__attribute__((packed));

struct acceptInfo
{
    uint8_t actionType;
}__attribute__((packed));

struct roomInfo
{
    uint16_t roomNum;
    char roomName[32];
    char roomDesc[32];
}__attribute__((packed));

struct characterInfo
{
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
    uint16_t initPoints;
    uint16_t statLimit;
    uint16_t gameDescLen;
}__attribute__((packed));

// struct leaveInfo
// {
//     const uint8_t pType = 12;
// }__attribute__((packed));

struct connectionInfo
{
    uint16_t roomNum;
    char roomName[32];
    uint16_t roomDescLen;
}__attribute__((packed));

struct versionInfo
{
    uint8_t lurkMajorRev;
    uint8_t lurkMinorRev;
    uint16_t extenListSize; // ignorable
}__attribute__((packed));