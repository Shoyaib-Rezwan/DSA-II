#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT32_MAX
using namespace std;
void dijkstra(vector<vector<pii>> &adj, int u, vector<int> &distance, vector<int> &layover, vector<int> &parent)
{
    distance[u] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, u});
    while (!pq.empty())
    {
        u = pq.top().second;
        int time_u = pq.top().first;
        pq.pop();
        if (time_u > distance[u])
            continue;
        for (pii x : adj[u])
        {
            int v = x.first, t = x.second;
            if (distance[v] > time_u + t + layover[v])
            {
                distance[v] = time_u + t + layover[v];
                pq.push({distance[v], v});
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
    int n, f;
    cin >> n >> f;
    map<string, int> mp1;
    map<int, string> mp2;
    vector<int> layover(n);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        mp1[a] = i;
        mp2[i] = a;
        cin >> layover[i];
    }
    vector<vector<pii>> adj(n);
    for (int i = 0; i < f; i++)
    {
        string a1, a2;
        int t;
        cin >> a1 >> a2 >> t;
        int u = mp1[a1], v = mp1[a2];
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    string s, d;
    cin >> s >> d;
    vector<int> distance(n, INF), parent(n, -1);
    dijkstra(adj, mp1[s], distance, layover, parent);
    cout << distance[mp1[d]] << '\n';
    vector<int> path;
    getPath(mp1[s], mp1[d], parent, path);
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << mp2[path[i]] << "-> ";
    }
    cout << mp2[path[path.size() - 1]];
}