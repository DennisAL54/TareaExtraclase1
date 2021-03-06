#include "grafo.h";//Importamos la clase grafo
void grafo::Inicialize()//Inicializamos el grafo
{
    h = NULL;//Inicializamos en nulo
}

bool grafo::Empty()//Boolean que indica si el grafo esta vacio
{
    if(h==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int grafo::Size()// Tamano del Grafo
{
    int counter = 0;
    Vertice *aux;
    aux = h;
    while(aux!=NULL)
    {
        counter++;
        aux = aux -> next;
    }
    return counter;
}
Vertice *grafo::GetV(int data)//Funcion para obtener Vertices
{
    Vertice *aux;
    aux = h;
    while(aux != NULL)
    {
        if(aux->data == data)
        {
            return aux;
        }
        aux = aux -> next;
    }
    return NULL;
}
void grafo::InsertV(int data)//Funcion para insertar Vertices
{
    Vertice *nuevo = new Vertice;
    nuevo -> data = data;
    nuevo -> next = NULL;
    nuevo -> ady = NULL;
    if(Empty())
    {
        h = nuevo;
    }
    else
    {
        Vertice *aux;
        aux = nuevo;
        while(aux -> next != NULL)
        {
            aux = aux -> next;
        }
        aux -> next = nuevo;
    }
}
void grafo::InsertA(Vertice *inicio, Vertice *fin, int peso)//Funcion para insertar Aristas
{
    Arista *nueva = new Arista();
    nueva -> peso = peso;
    nueva -> next = NULL;
    nueva -> ady = NULL;
    Arista *aux;
    aux = inicio -> ady;

    if(aux == NULL)
    {
        inicio -> ady = nueva;
        nueva -> ady = fin;
    }
    else
    {
        while(aux -> next != NULL)
        {
            aux = aux -> next;
        }
        aux -> next = nueva;
        aux -> ady = fin;
    }
}
void grafo::ListaAdy()
{
    Vertice *VAux;
    Arista *ArAux;
    VAux = h;
    
    while(VAux != NULL)
    {
        cout<<VAux -> data<<"->";
        ArAux = VAux->ady;
        while (ArAux != NULL)
        {
            cout<<ArAux->ady->data<<"->";
            ArAux = ArAux->next;
        }
        VAux = VAux->next;
        cout<<endl;
    }
}