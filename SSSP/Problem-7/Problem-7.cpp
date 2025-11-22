#include <bits/stdc++.h>
#define pii pair<int, int>
#define vi vector<int>
#define INF INT32_MAX
using namespace std;
void getPath(vector<int> &parent, vector<int> &path, int s, int u)
{
    if (s == u)
        path.push_back(s);
    else
    {
        getPath(parent, path, s, parent[u]);
        path.push_back(u);
    }
}
int main()
{
    int k, n, x;
    cin >> k >> n >> x;
    vector<vector<vi>> adj(n);
    vector<vector<int>> times(n, vector<int>(n));
    for (int i = 0; i < x; i++)
    {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        u--;
        v--;
        adj[u].push_back({v, t, c});
        adj[v].push_back({u, t, c});
        times[u][v] = t;
        times[v][u] = t;
    }
    int s, d;
    cin >> s >> d;
    s--;
    d--;
    vector<int> distance(n, INF);
    distance[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    vector<int> parent(n, -1);
    while (!pq.empty())
    {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();
        if (dist_u > distance[u])
            continue;
        for (vi x : adj[u])
        {
            int v = x[0], t = x[1], c = x[2];
            if (distance[v] > dist_u + c + k * (t + 1))
            {
                distance[v] = dist_u + c + k * (t + 1);
                pq.push({distance[v], v});
                parent[v] = u;
            }
        }
    }
    if (distance[d] == INF)
    {
        cout << "Error";
    }
    else
    {
        vector<int> path;
        int time = 0;
        getPath(parent, path, s, d);
        for (int i = 0; i < path.size() - 1; i++)
        {
            cout << path[i] + 1 << "->";
            time += times[path[i]][path[i + 1]];
        }
        cout << path[path.size() - 1] + 1 << ' ' << time + path.size() - 2 << ' ';
        cout << distance[d] - k;
    }
}