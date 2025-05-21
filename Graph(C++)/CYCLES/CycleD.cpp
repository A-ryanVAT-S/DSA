#include <bits/stdc++.h>
using namespace std;

// We have to check whether a directed graph has cycle or not.

// dfs
bool checkdfs(int node, vector<int> &vs, vector<int> &pathvis, vector<int> adjL[])
{
    vs[node] = 1;
    pathvis[node] = 1;
    for (auto s : adjL[node])
    {
        if (!vs[s])
        {
            if (checkdfs(s, vs, pathvis, adjL))
                return true;
        }
        else if (pathvis[s] == 1)
            return true;
    }
    pathvis[node] = 0;
    return false;
};
bool checkCycle(int v, vector<int> adjL[])
{
    vector<int> vs(v, 0);
    vector<int> pathvis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vs[i])
        {
            if (checkdfs(i, vs, pathvis, adjL))
                return true;
        }
    }
    return false;
}
