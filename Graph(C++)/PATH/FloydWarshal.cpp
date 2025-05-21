// we need a algo to find the shortest path between all pairs of vertices in a graph
// we can use floyd warshall algo

// basic idea of floyd warshall algo is to use dynamic programming
//  we will use a 2D array to store the shortest path between all pairs of vertices
//  for all diagonal elements of the array we will set the value to 0,put all the edges in the array and rest infinity
// next we will iterate through the array and for each pair of vertices we will check if there is a shorter path
// between them using the current vertex as an intermediate vertex
// computationally expensive algo as tc is O(n^3) and sc is O(n^2)

#include <bits/stdc++.h>
using namespace std;

void floydWarshall(int graph[][3], int V)
{
    int dist[V][V];

    // Initialize the distance array with the given graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (graph[i][j] != 0)
            {
                dist[i][j] = graph[i][j];
            }
            else
            {
                dist[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix

    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

//  if we have given sourc and target vertex we can also find the shortest path between them

int floydWarshall(int graph[][3], int V, int src, int target)
{
    int dist[V][V];

    // Initialize the distance array with the given graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (graph[i][j] != 0)
            {
                dist[i][j] = graph[i][j];
            }
            else
            {
                dist[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist[src][target];
}

// for negative cycle detection we can check if the distance from a vertex to itself is negative
// just add this inside the floyd warshall function after the main loop
for (int i = 0; i < V; i++)
{
    if (dist[i][i] < 0)
    {
        cout << "Negative cycle detected" << endl;
        return;
    }
}
// {as how distance to itself can be negative }