#include"headers/helperfunc.h"

#define BUFSIZE 1024*1024

void* readThread(void* param)
{
    struct socketInfo* sfd = (struct socketInfo*)param;
    char response[BUFSIZE];
    int readSize = 0;
}