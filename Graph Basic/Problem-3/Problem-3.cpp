#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &adj, vector<char> &color, stack<int> &stk, int u, bool &cyclic)
{
    color[u] = 'G';
    for (int v : adj[u])
    {
        if (color[v] == 'G')
        {
            cyclic = true;
        }
        else if (color[v] == 'W')
        {
            DFS(adj, color, stk, v, cyclic);
        }
    }
    color[u] = 'B';
    stk.push(u);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int> stk;
    vector<char> color(n, 'W');
    bool cyclic = false;
    for (int u = 0; u < n; u++)
    {
        if (color[u] == 'W')
        {
            DFS(adj, color, stk, u, cyclic);
        }
    }
    if (cyclic)
    {
        cout << -1;
    }
    else
    {
        while (!stk.empty())
        {
            cout << stk.top() << ' ';
            stk.pop();
        }
    }
}