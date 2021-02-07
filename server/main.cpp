#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Hello world!");
    }
    return 0;
}