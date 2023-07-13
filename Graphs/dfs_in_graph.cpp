#include <bits/stdc++.h>

void dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &res)
{
    res.push_back(i);
    vis[i] = 1;

    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(j, adj, vis, res);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> dfsAns;
    vector<int> adj[V];
    vector<int> vis(V, 0);

    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(i, adj, vis, temp);
            dfsAns.push_back(temp);
        }
    }

    return dfsAns;
}