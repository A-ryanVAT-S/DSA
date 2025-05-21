#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);

int main()
{

    // BFS
    vector<int> ans;
    queue<int> pool;
    int V = 10; // no of nodes
    vector<int> vs(V, 0);
    vector<vector<int>> adjL(V);
    int node = 0;
    pool.push(node);
    vs[0] = 1;
    while (!pool.empty())
    {
        node = pool.front();
        pool.pop();
        ans.push_back(node);
        for (auto it : adjL[node])
        {
            if (!vs[it])
            {
                pool.push(it);
                vs[it] = 1;
            }
        }
    }
}
// DFS
void dfs(int node, vector<int> &vs, vector<vector<int>> &adjL, vector<int> &ans)
{
    vs[node] = 1;
    ans.push_back(node);
    for (auto s : adjL[node])
    {
        if (!vs[s])
        {
            dfs(s, vs, adjL, ans);
        }
    }
}