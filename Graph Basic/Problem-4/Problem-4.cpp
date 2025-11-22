#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<vector<int>> &adj, int u, int &count)
{
    int n = adj.size();
    vector<int> rank(n, -1);
    rank[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (rank[v] == -1)
            {
                rank[v] = rank[u] + 1;
                q.push(v);
                count++;
            }
        }
    }
    return rank;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> isGM(n, true);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        isGM[v] = false;
        adj[u].push_back(v);
    }
    vector<int> rank(n, -1);
    for (int u = 0; u < n; u++)
    {
        if (isGM[u])
        {
            int count = 0;
            vector<int> rank = BFS(adj, u, count);
            cout <<'\n'<< u + 1 << ' ' << count << '\n';
            for (int u = 0; u < n; u++)
            {
                if (rank[u] > 0)
                {
                    cout << u + 1 << ' ' << rank[u] << '\n';
                }
            }
        }
    }
}