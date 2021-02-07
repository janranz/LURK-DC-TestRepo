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

void readerThread(socketInfo p);
void processIncoming(int b);