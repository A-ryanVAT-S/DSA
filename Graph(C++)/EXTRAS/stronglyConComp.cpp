// Strongly Connected Components(only for directed graphs)
// Kosaraju's Algorithm
//it is a directed graph algorithm that finds the strongly connected components of a directed graph.
// A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
// A directed graph is strongly connected if there is a path from any vertex to every other vertex.
//scc means that there is a path from any vertex to every other vertex in the component.


//Baiscally we have to do :
// 1. Do a DFS on the original graph to get the finishing times of each vertex.
// 2. Reverse the graph.
// 3. Do a DFS on the reversed graph in the order of decreasing finishing times.
// 4. Each time we finish a DFS, we have found a strongly connected component.
// 5. Repeat until all vertices are visited.

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V + E) for the graph and the stack used in DFS
// Note: This algorithm is not suitable for undirected graphs, as it will not find all the connected components.

#include <bits/stdc++.h>
using namespace std;

// DFS to fill stack with vertices in order of finishing time
void dfsFinish(int v, vector<bool>& visited, stack<int>& Stack, vector<vector<int>>& graph) {
    visited[v] = true;
    for (int i : graph[v])
        if (!visited[i])
            dfsFinish(i, visited, Stack, graph);

    Stack.push(v);
}

// DFS to collect nodes in one strongly connected component
void dfsCollect(int v, vector<bool>& visited, vector<int>& component, vector<vector<int>>& reversedGraph) {
    visited[v] = true;
    component.push_back(v);// Add the node to the current component

    for (int i : reversedGraph[v])
        if (!visited[i])
            dfsCollect(i, visited, component, reversedGraph);
}

// Kosaraju’s Algorithm
vector<vector<int>> getSCC(int V, vector<vector<int>>& graph) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    // Step 1: Order vertices by finish time
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsFinish(i, visited, Stack, graph);

    // Step 2: Reverse the graph
    vector<vector<int>> reversedGraph(V);
    for (int i = 0; i < V; i++)
        for (int j : graph[i])
            reversedGraph[j].push_back(i);

    // Step 3: Collect SCCs
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    while (!Stack.empty()) {
        int node = Stack.top();
        Stack.pop();

        if (!visited[node]) {
            vector<int> component;
            dfsCollect(node, visited, component, reversedGraph);
            sccs.push_back(component);
        }
    }

    return sccs;
}
