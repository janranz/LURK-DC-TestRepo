#include"headers/helperfunc.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<vector>


using namespace std;

void readerThread(socketInfo sk)
{
    // dip one byte to check type
    uint8_t dipByte;

    while(1)
    {
        
        int bytes = recv(sk.sktFd,&dipByte,1,MSG_WAITALL);

        if(bytes < 1)
        {
            printf("Done here! Bytes received: %d\n",bytes);
            break;
        }
        processIncoming(sk,dipByte);
        // cout << typeid(*dipByte).name() << endl;
        
        // printf("Bytes: %d\tdipByte: %d\n",bytes,dipByte);
    }
}

void processIncoming(socketInfo sk, uint8_t p)
{
    switch(p)
    {
        case 1:
        // pmIn
            pmIn(sk,p);
            break;
        case 7:
        // errIn
            errIn(sk,p);
            break;
        case 8:
        // acptIn
            acptIn(sk,p);
            break;
        case 9:
        // rmIn
            rmIn(sk,p);
            break;
        case 10:
        // charIn
            charIn(sk,p);
            break;
        case 11:
        // gameIn
            gameIn(sk,p);
            break;
        case 13:
        // cnctIn
            cnctIn(sk,p);
            break;
        case 14:
        // VersIn
            versIn(sk,p);
            break;
        default:
            // bad byte recv ... return
            printf("Bad byte: %d\n",p);
    }
}

void pmIn(socketInfo sk, uint8_t p)
{
    printf("pmIn\n");
}
void errIn(socketInfo sk, uint8_t p)
{
    printf("errIn\n");
}
void acptIn(socketInfo sk, uint8_t p)
{
    printf("acptIn\n");
}
void rmIn(socketInfo sk, uint8_t p)
{
    printf("rmIn\n");
}
void charIn(socketInfo sk, uint8_t p)
{
    printf("charIn\n");
}
void gameIn(socketInfo sk, uint8_t p)
{
    gameInfo gi;
    recv(sk.sktFd,&gi,sizeof(gi),MSG_WAITALL);
    char description[gi.gameDescLen + 1];
    recv(sk.sktFd, description,gi.gameDescLen, MSG_WAITALL);
    description[gi.gameDescLen] = 0;
    printf("TYPE: %dINITIAL POINTS: %d\nSTAT LIMIT: %d\nDESCRIPTION: %s\n",p,gi.initPoints,gi.statLimit,description);
}
void cnctIn(socketInfo sk, uint8_t p)
{
    printf("cnctIn\n");
}
void versIn(socketInfo sk, uint8_t p)
{
    versionInfo vi;
    recv(sk.sktFd,&vi,sizeof(vi),MSG_WAITALL);
    char description[vi.extenListSize + 1];
    recv(sk.sktFd, description, vi.extenListSize, MSG_WAITALL);
    description[vi.extenListSize] = 0;

    printf("TYPE: %d\nLURK VERSION: %d.%d\nEXTENSION LIST SIZE: %d\n"
        ,p,vi.lurkMajorRev,vi.lurkMinorRev,vi.extenListSize);
}

void senderThread(socketInfo)
{
    // G-O-OPS for init connection (character create).. Ask Seth about an initial mutex to block premature init write
    
    
}