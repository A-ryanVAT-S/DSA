// Dijkstra Algorithm Implementation
// it is used to find the shortest path from a source node to all other nodes in a graph
// Time Complexity: O(V^2) where V is the number of vertices in the graph
// Space Complexity: O(V) where V is the number of vertices in the graph

// there are thre methods to implement Dijkstra algorithm
// 1.priority queue 2.Set

// there should be no negative weight edges in the graph

#include <bits/stdc++.h>
using namespace std;

// using priority queue

// basically what we are doing is
//  1. we are taking the source node and pushing it into the priority queue
//  2. we are taking the top element of the priority queue and checking its neighbours
//  3. if the distance of the current node + the weight of the edge is less than the distance of the neighbour node
//  4. if it is less than we are updating the distance of the neighbour node and pushing it into the priority queue
//  5. we are doing this until the priority queue is empty
//  why priority queue instead of stack as earlier?
//  because we want to get the minimum distance node first , and stack will give us the last element added to it
// but priority queue will give us the minimum distance node first

vector<int> dijkstra(int source, vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
// with set

vector<int> dijkstra(int source, vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty())
    {
        auto it = *(s.begin());
        int u = it.second;
        int d = it.first;
        s.erase(it);

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            { // erase the old distance of v from the set
                // and insert the new distance of v into the set
                if (dist[v] != INT_MAX)
                {
                    s.erase({dist[v], v});
                }
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }

    return dist;
}

// why both of them are same?
//  because both of them are doing the same thing
//  the only difference is that in the first one we are using priority queue and in the second one we are using set
//  but both of them are doing the same thing
//  the time complexity of both of them is O(V^2) where V is the number of vertices in the graph
//  the space complexity of both of them is O(V) where V is the number of vertices in the graph

// printing the shortest path using dijkstra algorithm using parent array
//  1. we are taking the source node and pushing it into the priority queue
//  2. we are taking the top element of the priority queue and checking its neighbours
//  3. if the distance of the current node + the weight of the edge is less than the distance of the neighbour node
//  4. if it is less than we are updating the distance of the neighbour node and pushing it into the priority queue
//  5. we are doing this until the priority queue is empty
//  6. we are also keeping track of the parent of each node
//  7. we are doing this until the priority queue is empty

vector<int> dijkstra(int source, vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u; // update the parent of v
                pq.push({dist[v], v});
            }
        }
    }

    return parent;
}

// printing the shortest path using parent array
void printPath(int node, vector<int> &parent)
{
    if (node == -1)
        return;
    printPath(parent[node], parent);
    cout << node << " ";
}