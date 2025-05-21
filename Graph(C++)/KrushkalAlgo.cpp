// Kruskal's Algorithm implementation in C++
// we have to sort the edges by weight and then add them to the MST if they do not create a cycle
// we will use the union by size and path compression to keep the tree flat

#include <bits/stdc++.h>
using namespace std;

// Function to find the parent of a node using path compression
int find(int u, vector<int> &parent)
{
    // If the node is its own parent, return it
    if (parent[u] == u)
        return u;
    // Otherwise, find the parent of the node and perform path compression
    return parent[u] = find(parent[u], parent);
}

// Function to perform union of two nodes using union by size
void unionNodes(int u, int v, vector<int> &parent, vector<int> &size)
{
    // Find the parents of the two nodes
    int parentU = find(u, parent);
    int parentV = find(v, parent);

    // If they are already in the same set, do nothing
    if (parentU == parentV)
        return;

    // Union by size as we need size to be same
    // Attach the smaller tree under the larger tree as smaller has less nodes so less work
    if (size[parentU] < size[parentV])
    {
        parent[parentU] = parentV;
        size[parentV] += size[parentU];
    }
    else
    {
        parent[parentV] = parentU;
        size[parentU] += size[parentV];
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
vector<pair<int, pair<int, int>>> kruskalMST(int V, vector<vector<int>> &edges)
{
    // Create a parent array to store the parent of each node
    vector<int> parent(V);
    // Create a size array to store the size of each node
    vector<int> size(V, 1);

    // Initialize the parent array with each node as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Create a vector to store the edges of the graph
    vector<pair<int, pair<int, int>>> graphEdges;

    // Convert the edges to the required format and add them to the graphEdges vector
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        graphEdges.push_back({wt, {u, v}});
    }

    // Sort the edges based on their weights
    sort(graphEdges.begin(), graphEdges.end());

    // Vector to store the minimum spanning tree edges
    vector<pair<int, pair<int, int>>> mst;

    // Iterate through the sorted edges and add them to the MST if they do not create a cycle
    for (auto &edge : graphEdges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // Find the parents of the two nodes
        int parentU = find(u, parent);
        int parentV = find(v, parent);

        // If they are not in the same set, add the edge to the MST and perform union
        if (parentU != parentV)
        {
            mst.push_back({wt, {u, v}});
            unionNodes(u, v, parent, size);
        }
    }

    return mst; // Return the minimum spanning tree edges
}

// what we are doing ? / basic steps :
// 1. Create a parent array to store the parent of each node
// 2. Create a size array to store the size of each node
// 3. Initialize the parent array with each node as its own parent
// 4. Create a vector to store the edges of the graph
// 5. Convert the edges to the required format and add them to the graphEdges vector,
//    required formmat is {wt, {u, v}} as we are sorting the edges based on their weights.
// 6. Sort the edges based on their weights
// 7. Iterate through the sorted edges and add them to the MST if they do not create a cycle
//for checking cycle we will use union by size and path compression, as if there is a cycle then union will not be possible

// 8. Find the parents of the two nodes
// 9. If they are not in the same set, add the edge to the MST and perform union
// 10. Return the minimum spanning tree edges