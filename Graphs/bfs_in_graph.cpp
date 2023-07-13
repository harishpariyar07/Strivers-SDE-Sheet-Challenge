#include <bits/stdc++.h>

void bfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &res)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        res.push_back(top);

        for (auto j : adj[top])
        {
            if (!vis[j])
            {
                // cout << j << endl;
                vis[j] = 1;
                q.push(j);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> vis(vertex, 0);
    vector<int> adj[vertex];
    vector<int> res;

    for (auto i : edges)
    {
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    for (int i = 0; i < vertex; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            bfs(i, vis, adj, res);
        }
    }

    return res;
}