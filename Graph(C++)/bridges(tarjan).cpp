// bridges are those edges which when removed , increases the number of connected components
// we use tarjan's algorithm to find bridges
// Time complexity : O(V + 2E)
// Space complexity : O(V + 2E)+O(3V)

//basic idea is to do a DFS and keep track of the discovery time and the lowest point reachable from that node
// if the lowest point reachable from a node is greater than the discovery time of its parent, then that edge is a bridge
//in simple,  we will keep 2 arrays, one for discovery time and one for the lowest point reachable from that node
// we will also keep a parent array to keep track of the parent of each node
// we will also keep a visited array to keep track of the visited nodes
// we will also keep a vector of pairs to store the bridges
// if(low[v] > disc[u]) then (u,v) is a bridge

//core logic is that bridges are those edges whose below subtree cant access the above node without 
//going through the edge so if the lowest point reachable from a child is greater than 
//the discovery time of the node, then that edge is a bridge
//o(V+E) simply means we will visit each node and each edge once
#include <bits/stdc++.h>
using namespace std;


void dfs(int node, int parent,vector<int> &vis,vector<vector<int>> &adj,vector<int> &timeIn,vector<int> &low,vector<pair<int,int>> &bridges,int &timer) {
    vis[node] = 1;
    timeIn[node] = low[node] = timer++;
    
    for (auto &child : adj[node]) {
        if (child == parent) continue; // skip the parent node
        if (!vis[child]) {
            dfs(child, node, vis, adj, timeIn, low, bridges, timer);
            low[node] = min(low[node], low[child]);
            if (low[child] > timeIn[node]) {
                bridges.push_back({node, child});
            }
        } else {//if the child is already visited then we will update the low value of the node
            // this means that the child is not a parent of the node
            low[node] = min(low[node], timeIn[child]);
        }
    }   
}


vector<pair<int,int>> Bridges(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);// adjacency list

    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<int> vis(n, 0);// visited array
    vector<int> timeIn(n, 0);// discovery time array
    vector<int> low(n, 0);// lowest point reachable array
    vector<pair<int,int>> bridges;// vector to store bridges
    int timer = 0;

    //dfs for each component
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, adj, timeIn, low, bridges, timer);
        }
    }
    
    return bridges; // return the found bridges
}
