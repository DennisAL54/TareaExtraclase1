#include <iostream>
#include <limits.h>
#include <stdio.h>

#define V 9

int minimalD(int dis[], bool ArDmSet[])
{
    int min = INT_MAX, m_index;
    for (int v = 0; v < V; v++)
        if (ArDmSet[v] == false && dis[v] <= min)
            min = dis[v], m_index = v;
    return m_index;
}
int impSol(int dis[])
{
    printf("vertice \t\ Distancia desde el punto fuente\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dis[i]);
}
void dijkstra(int graph[V][V], int fuent)
{
int dis[V];
bool ArDmSet[V];
for (int i = 0; i < V; i++)
        dis[i] = INT_MAX, ArDmSet[i] = false;
dis[fuent] = 0;
for (int count = 0; count < V - 1; count++){
    int u = minimalD(dis, ArDmSet);
    ArDmSet[u] = true;
    for (int v = 0; v < V; v++)
        if (!ArDmSet[v] && graph[u][v] && dis[u] != INT_MAX
            && dis[u] + graph[u][v] < dis[v])
            dis[v] = dis[u] + graph[u][v];
    }
    impSol(dis);
}
int main()
{
    int grafo[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(grafo,0);
    return 0;
}
