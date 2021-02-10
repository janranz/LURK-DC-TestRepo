#pragma once

#include"include/sktstructs.h"
#include<cstdint>



void readerThread(socketInfo);
void processIncoming(socketInfo,uint8_t);
void pmIn(socketInfo,uint8_t);
void errIn(socketInfo,uint8_t);
void acptIn(socketInfo,uint8_t);
void rmIn(socketInfo,uint8_t);
void charIn(socketInfo,uint8_t);
void gameIn(socketInfo,uint8_t);
void cnctIn(socketInfo,uint8_t);
void versIn(socketInfo,uint8_t);

void senderThread(socketInfo);

// void processOutgoing(socketInfo,uint8_t);
// void chrmOut(socketInfo,uint8_t);
// void fightOut(socketInfo,uint8_t);
// void pvpOut(socketInfo,uint8_t);
// void lootOut(socketInfo,uint8_t);
// void startOut(socketInfo,uint8_t);
// void leaveOut(socketInfo,uint8_t);
// void pmOut(socketInfo,uint8_t);
// void charOut(socketInfo,uint8_t);
