#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &adj, int u, vector<char> &color, bool &isCyclic)
{
    color[u] = 'G';
    for (int v : adj[u])
    {
        if (color[v] == 'W')
        {
            DFS(adj, v, color, isCyclic);
        }
        else if (color[v] == 'G')
        {
            isCyclic = true;
        }
    }
    color[u] = 'B';
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<char> color(n, 'W');
    bool isCyclic = false;
    for (int u = 0; u < n; u++)
    {
        if (color[u] == 'W')
        {
            DFS(adj, u, color, isCyclic);
        }
    }
    if (!isCyclic)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}