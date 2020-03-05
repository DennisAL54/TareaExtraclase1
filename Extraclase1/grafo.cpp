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