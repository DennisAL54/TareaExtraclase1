#include <iostream>

using namespace std;

class Arista;

class Vertice
{
    Vertice *next;
    Arista *ady;
    int data;
    friend class grafo;
};
class Arista
{
    Arista *next;
    Vertice *ady;
    int peso;
    friend class grafo;
};
class grafo
{
    Vertice *h;
    public:
        void Inicialize();
        bool Empty();
        int Size();

};

