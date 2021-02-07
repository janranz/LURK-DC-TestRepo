#pragma once

#include"sktstructs.h"
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
// #include<pthread.h>
#include<thread>
#include<unistd.h>
#include<string.h>
#include<vector>

#define BUFSIZE 1024*1024

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