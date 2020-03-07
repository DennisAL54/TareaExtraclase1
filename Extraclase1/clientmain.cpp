#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "grafo.h"
using namespace std;

int main()
{
    int S = socket(AF_INET, SOCK_STREAM,0); //Creamos el Socket
    if(S == -1)
    {
        return 1;
    }
    int port = 54000;//Le asignamos un puerto
    string IP = "127,0,0";//Le asignamos una direccion ip
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, IP.c_str(), &hint.sin_addr);

    int connectR = connect(S, (sockaddr*)&hint, sizeof(hint));//Conectamos el server al socket
    if(connectR == -1)
    {
        return 1;
    }
    
}