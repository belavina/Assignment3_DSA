//
//  main.cpp
//  Assignment3
//
//  Created by Belavina on 2016-08-02.
//  Copyright © 2016 belavina. All rights reserved.
//

#include <iostream>

// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree


int minDistance(int dist[], bool visited[])
{
    // Initialize min value
    int min = INT_MAX, min_index = 0;
    
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
    
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;
    
    dist[src] = 0;

    for (int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        
        for (int v = 0; v < V; v++)

            if (!visited[v])
                if(graph[u][v] != 0)
                    if(dist[u] + graph[u][v] < dist[v])
                        dist[v] = dist[u] + graph[u][v];
    }
    
    printSolution(dist, V);
}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    
    
    int graph[V][V] =
    
    //   0  1  2  3  4  5  6  7  8
    //   --------------------------
       {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11,0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14,0, 0, 0},
        {0, 0, 0, 9, 0, 10,0, 0, 0},
        {0, 0, 4, 0, 10,0, 2, 0, 0},
        {0, 0, 0, 14,0, 2, 0, 1, 6},
        {8, 11,0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    dijkstra(graph, 0);
    
    return 0;
}
