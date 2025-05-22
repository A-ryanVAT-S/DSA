// Disjoint Set union basically used to find the connected components of a graph
//we basically do union and find operations
// union operation is used to merge two sets
// find operation is used to find the parent of a node

//steps
// 1. Create a parent array to store the parent of each node.
// 2. Create a rank array to store the rank of each node.
// 3. Initialize the parent array with each node as its own parent.
// 4. Initialize the rank array with all nodes having rank 0.
// 5. For each edge in the graph:
//    a. Find the parent of the first node using the find operation.
//    b. Find the parent of the second node using the find operation.
//    c. If the parents are different, perform the union operation to merge the two sets.
// 6. Return the parent array.
// 7. The time complexity is O(E log V) for union and find operations.
// 8. The space complexity is O(V) for the parent and rank arrays.

//as we just need to find the connected components we can use union by rank and path compression 
// as ultimately we need to find component not original parent and edges.

// //we have two ways
// 1. union by rank
// 2. union by size


//union by rank is used to keep the tree flat by attaching the smaller tree under the larger tree
#include <bits/stdc++.h>
using namespace std;

int find(int u , vector<int> &parent)
{
    // If the node is its own parent, return it
    if (parent[u] == u)
        return u;
    // Otherwise, find the parent of the node and perform path compression
    return parent[u] = find(parent[u], parent);
}

void unionNodes(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // Find the parents of the two nodes
    int parentU = find(u, parent);
    int parentV = find(v, parent);

    // If they are already in the same set, do nothing
    if (parentU == parentV)
        return;

    // Union by rank as we need rank to be same
    // Attach the smaller tree under the larger tree as smaller has less nodes so less work
    if (rank[parentU] < rank[parentV])
    {
        parent[parentU] = parentV;
        rank[parentV]+=rank[parentU];}
    // Attach the smaller tree under the larger tree as smaller has less nodes so less work
    else if (rank[parentU] > rank[parentV])
       { parent[parentV] = parentU;
        rank[parentU] += rank[parentV];}
    else
    {
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}

int numberOfConnectedComponents(int V, vector<vector<int>> &edges)
{
    // Create a parent array to store the parent of each node
    vector<int> parent(V);
    // Create a rank array to store the rank of each node
    vector<int> rank(V, 0);

    // Initialize the parent array with each node as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // For each edge in the graph, perform union operation
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        unionNodes(u, v, parent, rank);
    }

    // Count the number of connected components
    unordered_set<int> components;
    for (int i = 0; i < V; i++)
        components.insert(find(i, parent));

    return components.size();
}

//union by size is used to keep the tree flat by attaching the smaller tree under the larger tree
//we can use union by size and path compression

// what we need to change is
// 1. Create a size array to store the size of each node.
// 2. Initialize the size array with all nodes having size 1.
// 3. For each edge in the graph:
//    a. Find the parent of the first node using the find operation.
//    b. Find the parent of the second node using the find operation.
//    c. If the parents are different, perform the union operation to merge the two sets.
// 6. Return the parent array.

// find fxn works same
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

int numberOfConnectedComponents(int V, vector<vector<int>> &edges)
{
    // Create a parent array to store the parent of each node
    vector<int> parent(V);
    // Create a size array to store the size of each node
    vector<int> size(V, 1);

    // Initialize the parent array with each node as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // For each edge in the graph, perform union operation
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        unionNodes(u, v, parent, size);
    }

    // Count the number of connected components
    unordered_set<int> components;
    for (int i = 0; i < V; i++)
        components.insert(find(i, parent));

    return components.size();
}