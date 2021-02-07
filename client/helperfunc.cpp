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
            pmIn(sk);
            break;
        case 7:
        // errIn
            errIn(sk);
            break;
        case 8:
        // acptIn
            acptIn(sk);
            break;
        case 9:
        // rmIn
            rmIn(sk);
            break;
        case 10:
        // charIn
            charIn(sk);
            break;
        case 11:
        // gameIn
            gameIn(sk);
            break;
        case 13:
        // cnctIn
            cnctIn(sk);
            break;
        case 14:
        // VersIn
            versIn(sk);
            break;
        default:
            // bad byte recv ... return
            printf("Bad byte: %d\n",p);
    }
}

void pmIn(socketInfo sk)
{
    printf("pmIn\n");
}
void errIn(socketInfo sk)
{
    printf("errIn\n");
}
void acptIn(socketInfo sk)
{
    printf("acptIn\n");
}
void rmIn(socketInfo sk)
{
    printf("rmIn\n");
}
void charIn(socketInfo sk)
{
    printf("charIn\n");
}
void gameIn(socketInfo sk)
{
    printf("gameIn\n");
}
void cnctIn(socketInfo sk)
{
    printf("cnctIn\n");
}
void versIn(socketInfo sk)
{
    versionInfo vi;
    int bytes = recv(sk.sktFd,&vi,sizeof(vi),MSG_WAITALL);
    char description[vi.extenListSize + 1];
    recv(sk.sktFd, description, vi.extenListSize, MSG_WAITALL);
    description[vi.extenListSize] = 0;
    printf("TYPE: %d\nLURK VERSION: %d.%d\nEXTENSION LIST SIZE: %d\n"
        ,vi.pType,vi.lurkMajorRev,vi.lurkMinorRev,vi.extenListSize);
}