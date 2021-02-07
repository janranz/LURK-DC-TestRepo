#include "headers/helperfunc.h"


using namespace std;

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Invalid number of arguments. Run: %s HOST PORT\n",argv[0]);
        return 1;
    }
    // build server address struct
    struct sockaddr_in sd;

    //verify host name checks out
    struct hostent* host = gethostbyname(argv[1]);
    if(!host)
    {
        // failed to retrieve gethostbyname
        // handle h_errno failures: http://rabbit.eng.miami.edu/info/functions/errors.html#h_errno
        switch(h_errno)
        {
            case 1:
                printf("Error %d: HOST_NOT_FOUND...\n",h_errno);
                break;
            case 2:
                printf("Error %d: SERVERFAIL...\n",h_errno);
                break;
            case 3:
                printf("Error %d: NO_RECOVERY...\n",h_errno);
                break;
            case 4:
                printf("Error %d: NO_DATA...\n",h_errno);
                break;
            default:
                printf("Error %d: Unexpected h_errno error...\n",h_errno);
        }
        return 1;
    }
    // continue building struct
    struct in_addr **addr_list = (struct in_addr**)host->h_addr_list;
    sd.sin_port = htons(atoi(argv[2]));
    sd.sin_family = AF_INET;
    struct in_addr* c_addr = addr_list[0];
    char* ip_string = inet_ntoa(*c_addr);
    sd.sin_addr = *c_addr;

    // establish connection to server
    printf("Attempting to connect to: %s\n",ip_string);
    int sktFD = socket(AF_INET, SOCK_STREAM, 0);
    int cnct = connect(sktFD, (struct sockaddr*)&sd, sizeof(struct sockaddr_in));

    if(cnct != 0)
    {
        printf("Failed to connect to: %s\n... sorry about your luck.\n",ip_string);
        return 1;
    }

    socketInfo sockPack;
    sockPack.sktFd = sktFD;

    thread reader (readerThread,sockPack);
    reader.join();


    return 0;
}