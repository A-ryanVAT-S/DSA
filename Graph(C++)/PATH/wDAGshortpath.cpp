// we have given a directed acyclic graph and we have to find the shortest path from source to destination
class Solution
{
public:
    vector<vector<pair<int, int>>> edgetoAdjLW(vector<vector<int>> &edges, int n)
    {
        vector<vector<pair<int, int>>> ans(n);
        for (auto &s : edges)
        {
            ans[s[0]].push_back({s[1], s[2]});
        }
        return ans;
    }

    void toposort(stack<int> &pool, vector<int> &vs, vector<vector<pair<int, int>>> &adjL, int node)
    {
        vs[node] = 1;
        for (auto &s : adjL[node])
        {
            if (!vs[s.first])
            {
                toposort(pool, vs, adjL, s.first);
            }
        }
        pool.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        stack<int> pool;
        vector<vector<pair<int, int>>> adjL = edgetoAdjLW(edges, N);
        vector<int> vs(N, 0);

        for (int i = 0; i < N; i++)
        {
            if (!vs[i])
                toposort(pool, vs, adjL, i);
        }

        vector<int> dist(N);
        fill(dist.begin(), dist.end(), -1);
        dist[0] = 0;
        while (!pool.empty())
        {
            int node = pool.top();
            pool.pop();

            if (dist[node] == -1)
                continue;

            for (auto s : adjL[node])
            {
                int v = s.first;
                int w = s.second;
                if (dist[v] == -1 || dist[node] + w < dist[v])
                {
                    dist[v] = dist[node] + w;
                }
            }
        }

        return dist;
    }
};
