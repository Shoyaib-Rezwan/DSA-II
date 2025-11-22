#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT32_MAX
using namespace std;
void dijkstra(vector<vector<pii>> &adj, int u, vector<int> &distance)
{
    distance[u] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, u});
    while (!pq.empty())
    {
        u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();
        if (dist_u > distance[u])
        {
            continue;
        }
        for (pii x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (distance[v] > dist_u + w)
            {
                distance[v] = dist_u + w;
                pq.push({distance[v], v});
            }
        }
    }
}
int main()
{
    int n, m, f;
    cin >> n >> m >> f;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }
    int k;
    cin >> k;
    vector<int> cost(n, INF);
    dijkstra(adj, 0, cost);
    vector<pii> cost2(n);
    for (int i = 0; i < n; i++)
    {
        cost2[i] = {cost[i], c[i]};
    }
    sort(cost2.begin(), cost2.end());
    int i = 0;
    while (k > 0 && i < n)
    {
        if (cost2[i].second > 0)
        {
            cout << cost2[i].first + f << ' ';
            cost2[i].second--;
            k--;
        }
        else
        {
            i++;
        }
    }
    while (k > 0)
    {
        cout << -1 << ' ';
        k--;
    }
}