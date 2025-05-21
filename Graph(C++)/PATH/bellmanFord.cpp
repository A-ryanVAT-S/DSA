// as dijkstra's algorithm cant work with negative weights and negative cycles
// this algorithm can work with negative weights and negative cycles

// for belman ford algorithm we need graph to be directed and weighted
//  for undirected graph we need to convert it to directed graph
//(for eg if 1 to 5 gives weight 2 then we need to add 2 edges 1 to 5 and 5 to 1 with weight 2)

#include <bits/stdc++.h>
using namespace std;

// after it is directed and weighted we can use the bellman ford algorithm
//  relax all the edges n-1 times sequentially
//  relaxing means if the distance of the source node is less than the distance of the destination node then
//  update the distance of the destination node
// it needs to be done n-1 times because the longest path in a graph can have at most n-1 edges
//  we need edges not adjaceny list

vector<int> bellmanFord(int n, vector<vector<int>> edges, int source)
{
    // distance of all nodes from source
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // relax all edges n-1 times(each contains source and destination node and weight)
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for negative weight cycles
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative weight cycle detected" << endl;
            return {};
        }
    }

    return dist;
}
// time complexity is O(n*m) where n is the number of nodes and m is the number of edges
// space complexity is O(n) for distance array

// when to use it? : when we have negative weights and negative cycles
// when not to use it? : when we have positive weights and no negative cycles as it is slower than dijkstra's algorithm(O(elogv));
// why dijkstra's algorithm is faster? : because it uses priority queue and only relaxes the edges which are needed