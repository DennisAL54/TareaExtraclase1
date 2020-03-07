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
    /*int Listen = socket(AF_INET, SOCK_STREAM, 0);//Creamos un socket (server)
    if(Listen == -1)
    {
        cerr << "No se pudo crear";//Prevemos el caso que no se pueda crear
        return -1;
    }
    sockaddr_in pista;//Asignamos un puerto al socket
    pista.sin_family = AF_INET;
    pista.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &pista.sin_addr);
    if(bind(Listen, AF_INET, &pista) == -1)
    {
        cerr << "no se pudo vincular";
        return -2;
    }*/


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

