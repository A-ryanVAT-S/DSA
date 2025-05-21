// Tree: A connected acyclic graph.
// Spanning Tree: A tree that includes all vertices of a graph.
// MST (Minimum Spanning Tree): A spanning tree with the minimum total edge weight.(N vertics, N-1 edges,with minimal weight)

// How to find MST?
//  1. Prim's Algorithm
//  2. Kruskal's Algorithm

// 1. Prim's Algorithm:
// it will give the minimum spanning tree of a connected graph and minimum sum.
// Basic Idea:
// 1. Start with a vertex and add it to the MST.
// 2. Find the minimum weight edge that connects a vertex in the MST to a vertex outside the MST.
// 3. Add the vertex connected by that edge to the MST.
// 4. Repeat steps 2 and 3 until all vertices are included in the MST.
// 5. The time complexity is O(E log V) using a priority queue.
// 6. The space complexity is O(V) for the priority queue and O(E) for the adjacency list.
// 7. Ensure to handle disconnected graphs appropriately.

// Steps
//  1. Create a priority queue to store the edges of the graph.
//  2. Create a vector to store the minimum spanning tree.
//  3. Create a vector to keep track of the vertices included in the MST.
//  4. Initialize the priority queue with the edges of the graph.
//  5. While the priority queue is not empty:
//     a. Get the edge with the minimum weight from the priority queue.
//     b. If the vertex connected by that edge is not already included in the MST:
//        i. Add the vertex to the MST.
//        ii. Add the edge to the MST.
//     c. For each vertex connected to the vertex added to the MST:
//        i. If the edge connecting the vertex to the MST has a smaller weight than the current minimum weight:
//           - Update the minimum weight edge.
//  6. Return the minimum spanning tree.

#include <bits/stdc++.h>
using namespace std;

// fxn to find both the minimum spanning tree and its weight , just return array for tree and sum for weight

int primsMST(int V, vector<vector<pair<int, int>>> &edges, vector<int> &mst)
{
    // Create a priority queue to store the edges of the graph (wt, {node, parent})
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // visited array to keep track of visited vertices
    vector<bool> visited(V, false);

    // enter the first vertex in the priority queue
    pq.push({0, {0, -1}}); // {weight, {node, parent}}
    int totalWeight = 0;   // to store the total weight of the MST

    while (!pq.empty())
    {
        // Get the edge with the minimum weight
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        // If the vertex is already included in the MST, skip it
        if (visited[node])
            continue;

        // Mark the vertex as visited
        visited[node] = true;

        // Add the edge to the MST
        if (parent != -1)
            mst.push_back(parent);

        totalWeight += wt;

        // Add all edges connected to the vertex to the priority queue
        for (auto &edge : edges[node])
        {
            int adjNode = edge.first;
            int weight = edge.second;
            if (!visited[adjNode])
                pq.push({weight, {adjNode, node}});
        }
    }
    return totalWeight; // return the total weight of the MST
    // MST will be stored in the mst vector
}
