#include"headers/helperfunc.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<vector>


using namespace std;

void readerThread(socketInfo sk)
{
    // dip one byte to check type
    uint8_t **dipByte;

    while(1)
    {
        
        int bytes = recv(sk.sktFd,dipByte,1,MSG_WAITALL);

        if(bytes < 1)
        {
            printf("Done here! Bytes received: %d\n",bytes);
            break;
        }

        // printf("Bytes: %d\tdipByte: %d\n",bytes,dipByte[0]);
    }
}

void processIncoming(int p)
{
    switch(p)
    {
        case 1:

        case 2:
        case 3
        case 4
        case 5
        case 6
        case 7
        case 8
        case 9
        case 10
        case 11
        case 12
        case 13
        case 14
    }
}

void ()
{

}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}
void ()
{
    
}