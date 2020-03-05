#include "grafo.h";
void grafo::Inicialize()
{
    h = NULL;
}

bool grafo::Empty()
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
int grafo::Size()
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
Vertice *grafo::GetV(int data)
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
void grafo::InsertV(int data)
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
void grafo::InsertA(Vertice *inicio, Vertice *fin, int peso)
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