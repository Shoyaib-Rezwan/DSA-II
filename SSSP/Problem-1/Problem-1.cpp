#include <bits/stdc++.h>
#define INF INT32_MAX
#define pii pair<int, int>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tax(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tax[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int> distance(n, INF);
    distance[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second, dist_u = pq.top().first;
        pq.pop();
        if (distance[u] < dist_u)
            continue;
        for (int v : adj[u])
        {
            if (distance[v] > dist_u + tax[v])
            {
                distance[v] = dist_u + tax[v];
                pq.push({distance[v], v});
            }
        }
    }
    cout << distance[n - 1];
}