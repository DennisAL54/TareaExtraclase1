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
    int listening = socket(AF_INET, SOCK_STREAM, 0);//Creamos un socket (server)
    if(listening == -1)
    {
        cerr << "No se pudo crear";//Prevemos el caso que no se pueda crear
        return -1;
    }
    sockaddr_in hint;//Asignamos un puerto al socket
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
    if(bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1)//Vinculamos
    {
        cerr << "no se pudo vincular";
        return -2;
    }
    if(listen(listening, SOMAXCONN) == -1)//Hacemos que el socket escuche
    {
        cerr<<"El socket no puede escuchar";
        return -3;
    }
    sockaddr_in client;// Esto se usa para aceptar una llamada
    socklen_t Tclient = sizeof(client);
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];
    int clientS = accept(listening, (sockaddr*)&client, &Tclient);
    if(clientS == -1)
    {
        cerr << "Problema con conexion al cliente";
        return -4;
    }
    close(listening);//Cerramos el socket
    memset(host,0,NI_MAXHOST);//limpiamos
    memset(svc,0,NI_MAXSERV);
    int resultado = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV,0);

    if(resultado)//imprimimos resultados
    {
        cout << host << "conectado a" << svc << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << "conectado a" << ntohs(client.sin_port) << endl;
    }
    char buf[4096];//buscamos que el server se mantenga activo mientras reciba mensajes
    while(true)
    {
        memset(buf,0,4096);
        int bytesR = recv(clientS, buf, 4096,0);
        if(bytesR == -1);
        {
            cerr << "Hubo un error en la conexion" << endl;//Mostramos errores en la conexion
            break;
        }
        if(bytesR == 0)
        {
            cout << "El cliente se desconecto" << endl;//Notificamos la desconexion del cliente
            break;
        }
        cout << "Recibido:" string(buf,0,bytesR) << endl;//Mostramos el mensaje recibido del cliente
        send(clientS, buf, bytesR + 1, 0);

        close(clientS);//Cerramos el socket
        return 0;

    }
    

    grafo G;//Creamos un grafo
    G.Inicialize();//Lo inicializamos
    G.InsertV(25);//Agregamos Vertices
    G.InsertV(26);
    G.InsertV(27);
    G.InsertV(28);
    G.InsertV(29);
    G.InsertV(30);
    G.InsertA(G.GetV(25), G.GetV(27), 35);//Agregamos Aristas
    G.InsertA(G.GetV(25), G.GetV(28), 36);
    G.InsertA(G.GetV(25), G.GetV(30), 37);
    G.InsertA(G.GetV(26), G.GetV(29), 38);
    G.InsertA(G.GetV(26), G.GetV(27), 39);
    G.InsertA(G.GetV(27), G.GetV(30), 50);
    G.InsertA(G.GetV(28), G.GetV(26), 51);
    G.InsertA(G.GetV(29), G.GetV(30), 52);
    G.InsertA(G.GetV(29), G.GetV(25), 53);
    G.InsertA(G.GetV(29), G.GetV(27), 54);
    G.InsertA(G.GetV(30), G.GetV(29), 55);
    G.ListaAdy();//Creamos la lista de ady

}

