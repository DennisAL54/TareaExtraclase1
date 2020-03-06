#include <iostream>

using namespace std;

class Arista;// Declaramos la clase Arista

class Vertice //Construimos la clase Vertice
{
    Vertice *next;//Vertice siguiente
    Arista *ady;//Arista adyacente
    int data;//El dato INT que contendra el Vertice
    friend class grafo;
};
class Arista //Construimos la clase Arista
{
    Arista *next; //Puntero Arista "Siguiente"
    Vertice *ady; //Puntero Vertice "Adyacente"
    int peso; //El peso de la Arista
    friend class grafo; //La relacionamos con grafo
};
class grafo //Construimos la clase Grafo
{
    Vertice *h; //Generamos un puntero Vertice
    public: //Inicializamos las funciones que tendra el grafo
        void Inicialize(); //Funcion para inicializar
        bool Empty(); //Booleano que detecta si el grafo esta vacio
        int Size(); //Tamano del grafo
        Vertice *GetV(int data); //Funcion para obtener una vertice
        void InsertA(Vertice *inicio, Vertice *fin, int peso);//Insertar Arista
        void InsertV(int data);//Insertar Vertice
        void ListaAdy();//Lista de adyacencia

};

