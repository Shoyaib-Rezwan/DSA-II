#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT32_MAX
using namespace std;
void dijkstra(vector<vector<pii>> &adj, int s, vector<int> &time, vector<int> &parent)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    time[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int u = pq.top().second, time_u = pq.top().first;
        pq.pop();
        if (time_u > time[u])
            continue;
        for (pii x : adj[u])
        {
            int v = x.first, t = x.second;
            if (time[v] > time[u] + t)
            {
                time[v] = time[u] + t;
                pq.push({time[v], v});
                parent[v] = u;
            }
        }
    }
}
void getPath(int s, int u, vector<int> &parent, vector<int> &path)
{
    if (s == u)
        path.push_back(s);
    else
    {
        getPath(s, parent[u], parent, path);
        path.push_back(u);
    }
}
int main()
{
    int s, r;
    cin >> s >> r;
    vector<vector<pii>> adj(s);
    for (int i = 0; i < r; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
    }
    int f;
    cin >> f;
    vector<int> time1(s, INF), time2(s, INF), parent1(s, -1), parent2(s, -1);
    dijkstra(adj, f, time1, parent1);
    vector<vector<pii>> adj2(s);
    for (int u = 0; u < s; u++)
    {
        for (pii x : adj[u])
        {
            int v = x.first, t = x.second;
            adj2[v].push_back({u, t});
        }
    }
    dijkstra(adj2, f, time2, parent2);
    int minTime = INF, target = -1;
    for (int u = 0; u < s; u++)
    {
        if (u == f)
            continue;
        if (minTime > time1[u] + time2[u])
        {
            minTime = time1[u] + time2[u];
            target = u;
        }
    }
    cout << "Minimum total time: " << minTime << '\n';
    vector<int> path1, path2;
    getPath(f, target, parent1, path1);
    getPath(f, target, parent2, path2);
    cout << "Paths:\n";
    for (int i = 0; i < path1.size() - 1; i++)
    {
        cout << path1[i] << "->";
    }
    cout << path1[path1.size() - 1] << " (time: " << time1[target] << ")\n";
    for (int i = path2.size() - 1; i > 0; i--)
    {
        cout << path2[i] << "->";
    }
    cout << path2[0] << " (time: " << time2[target] << ")\n";
}