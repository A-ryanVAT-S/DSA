// we have to find the shortest path from a source to a destination in a
// constant(1) weigted undirected graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n);

        // Build undirected graph
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS to find the shortest path
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> distance(n, INT_MAX);

        q.push(source);
        visited[source] = true;
        distance[source] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                for (int neighbor : adj[node]) {
                    if (distance[neighbor] > distance[node] + 1) {
                        distance[neighbor] = distance[node] + 1;
                        q.push(neighbor);
                    }
                }

            }
        }

        return (distance[destination] == INT_MAX) ? -1 : distance[destination];
    }
};
