#pragma once
#include<cstdint>

struct socketInfo
{
    int sktFd;
};

struct dialogue
{
    const string greet = "\n...Welcome to DubClient...\nBuild your Character.\n";
    const string n = "Name: ";
    const string j = "Automatically join battles? (y/n): ";
    // const string 

    // common use
    const char errsize = 4;
    const char *err[4] = {
        "\nYou have made an error in judgement. I will ask you again...\n",
        "\nOkay now I think you're doing it on purpose. Let's try this again...\n",
        "\nWe should be out there pushing forth the crusade, but you would rather fumble over foolish inputs.\nLet's give it another shot...\n",
        "\nYour foolish error was understandable and probably justified,\nbut it was a lapse of judgement to send it to me before consulting the dialogue.\nLet's try again...",

    }
    // const string err1 = "\nYou have made an error in judgement. I will ask you again...\n";
    // const string err2 = "\nOkay now I think you're doing it on purpose. Let's try this again...\n";
    // const string err3 = "\nWe should be out there pushing forth the crusade, but you would rather fumble over foolish inputs.\nLet's give it another shot...\n";

}

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