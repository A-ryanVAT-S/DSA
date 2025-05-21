// we have to check wheter a graph is bipartite or not

// bfs way
#include <bits/stdc++.h>
using namespace std;

// single one
bool bfsbpcheck(int node, vector<vector<int>> &adjL, vector<int> &vs)
{
    queue<int> pool;
    pool.push(node);
    vs[node] = 0;

    while (!pool.empty())
    {
        int node = pool.front();
        pool.pop();

        for (auto s : adjL[node])
        {
            if (vs[s] == -1)
            {
                pool.push(s);
                vs[s] = !vs[node];
            }
            else if (vs[s] == vs[node])
            {
                return false;
            }
        }
    }
    return true;
}
// multiple components
bool checkBpGraph(vector<vector<int>> &adjL)
{
    vector<int> vs(adjL.size(), -1);

    for (int i = 0; i < adjL.size(); i++)
    {
        if (vs[i] == -1)
        {
            if (!bfsbpcheck(i, adjL, vs))
                return false;
        }
    }
    return true;
}

// dfs
bool dfsbpcheck(int node, vector<vector<int>> &adjL, vector<int> &vs)
{ // vs is initialized to -1 // vs of starting node is 0(color 1)//next node color is 1(color 2)
    for (auto s : adjL[node])
    {
        if (vs[s] == -1)
        {
            vs[s] = !vs[node];
            if (!dfsbpcheck(s, adjL, vs))
                return false;
        }
        else if (vs[s] == vs[node])
        {
            return false;
        }
    }
    return true;
}