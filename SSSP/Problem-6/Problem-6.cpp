#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT32_MAX
using namespace std;
bool bellmanford(vector<vector<pii>> &adj, int u, vector<int> &distance)
{
    distance[u] = 0;
    int n = adj.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (pii x : adj[u])
            {
                int v = x.first, w = x.second;
                if (distance[u] != INF && distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    for (int u = 0; u < n; u++)
    {
        for (pii x : adj[u])
        {
            int v = x.first, w = x.second;
            if (distance[u] != INF && distance[v] > distance[u] + w)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, m, k, b, e;
    cin >> n >> m >> k >> b >> e;
    vector<int> capitals(k);
    for (int i = 0; i < k; i++)
    {
        cin >> capitals[i];
        capitals[i]--;
    }
    set<int> blocked;
    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        blocked.insert(x - 1);
    }
    vector<int> target(e);
    for (int i = 0; i < e; i++)
    {
        cin >> target[i];
        target[i]--;
    }
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (blocked.find(u) != blocked.end() || blocked.find(v) != blocked.end())
            continue;
        adj[u].push_back({v, w});
    }
    bool abyssDetected = false;
    vector<vector<int>> distance(k, vector<int>(n, INF));
    for (int i = 0; i < k; i++)
    {
        if (!bellmanford(adj, capitals[i], distance[i]))
        {
            abyssDetected = true;
        }
    }
    if (abyssDetected)
    {
        cout << "Abyss detected";
    }
    else
    {
        vector<int> minDist(e, INF);
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < e; j++)
            {
                minDist[j] = min(minDist[j], distance[i][target[j]]);
            }
        }
        for (int i = 0; i < e; i++)
        {
            if (minDist[i] == INF)
                cout << "INF\n";
            else
                cout << minDist[i] << '\n';
        }
    }
}