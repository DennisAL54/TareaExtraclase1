#include <iostream>
#include <limits.h>
#include <stdio.h>
#include "grafo.h"

using namespace std;

int main()
{
    grafo G;
    G.Inicialize();
    G.InsertV(25);
    G.InsertV(26);
    G.InsertV(27);
    G.InsertV(28);
    G.InsertV(29);
    G.InsertV(30);
    G.InsertA(G.GetV(25), G.GetV(27), 35);
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
    G.ListaAdy();

}

