//the points which when removed increase the number of connected components in a graph are called articulation points
//just like bridges, we will use tarjan's algorithm to find articulation points
//just the difference is that we will keep track of the number of children of each node
//if the lowest point reachable from a child is greater than the discovery time of the node, then that node is an articulation point
//if the node is root and has more than 1 child, then that node is an articulation point
//in simple, we will keep 2 arrays, one for discovery time and one for the lowest point reachable from that node
//we will also keep a parent array to keep track of the parent of each node
//we will also keep a visited array to keep track of the visited nodes
//we will also keep a vector to store the articulation points
//if(low[v] >= disc[u]) then u is an articulation point
//if the node is root and has more than 1 child, then that node is an articulation point

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, 
        vector<int> &timeIn, vector<int> &low, unordered_set<int> &articulationPoints, int &timer) {
    vis[node] = 1;
    timeIn[node] = low[node] = timer++;
    int children = 0; // to count the number of children of the node

    for (auto &child : adj[node]) {
        if (child == parent) continue; // skip the parent node
        if (!vis[child]) {
            dfs(child, node, vis, adj, timeIn, low, articulationPoints, timer);
            low[node] = min(low[node], low[child]);
            if (low[child] >= timeIn[node] && parent != -1) {
                articulationPoints.insert(node);
            }
            children++;
        } else { // if the child is already visited then we will update the low value of the node
            low[node] = min(low[node], timeIn[child]);
        }
    }

    // If the node is root and has more than 1 child
    if (parent == -1 && children > 1) {
        articulationPoints.insert(node); 
    }
}
vector<int> articulationPoints(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n); // adjacency list

    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(n, 0); // visited array
    vector<int> timeIn(n, 0); // discovery time array
    vector<int> low(n, 0); // lowest point reachable array
    unordered_set<int> articulationPoints; // vector to store articulation points
    int timer = 0;

    // dfs for each component
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, adj, timeIn, low, articulationPoints, timer);
        }
    }

    return vector<int>(articulationPoints.begin(), articulationPoints.end()); // return the found articulation points
}
//the basic difference between bridges and articulation points is that in bridges we will keep track of the lowest point reachable from a child
//and in articulation points we will keep track of the number of children of the node
//in code the difference is that in bridges we will check if low[child] > timeIn[node] and in articulation points we will check if low[child] >= timeIn[node]
//and in bridges we will not check if the node is root and has more than 1 child