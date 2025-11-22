#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    pii edge;
    queue<int> q;
    q.push(0);
    vector<int> parent(n, -1);
    bool isCyclic = false;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (v != parent[u])
            {
                if (parent[v] != -1)
                {
                    isCyclic = true;
                    edge = {u, v};
                    break;
                }
                else
                {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        if (isCyclic)
            break;
    }
    if(isCyclic)
    {
        cout << "YES\n"
             << edge.first + 1 << ' ' << edge.second + 1;
    }
    else
        cout << "NO";
}