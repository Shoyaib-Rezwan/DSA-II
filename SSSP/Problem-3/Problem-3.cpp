#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT32_MAX
using namespace std;
void dijkstra(vector<vector<pii>> &adj, int s, vector<int> &distance, vector<int> &parent)
{
    distance[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        int u = pq.top().second, dist_u = pq.top().first;
        pq.pop();
        if (dist_u > distance[u])
        {
            continue;
        }
        for (pii x : adj[u])
        {
            int v = x.first, w = x.second;
            if (distance[v] > dist_u + w)
            {
                distance[v] = dist_u + w;
                pq.push({distance[v], v});
                parent[v] = u;
            }
        }
    }
}
void getPath(vector<int> &parent, int s, int u, vector<int> &path)
{
    if (u == s)
    {
        path.push_back(u);
    }
    else
    {
        getPath(parent, s, parent[u], path);
        path.push_back(u);
    }
}
int main()
{
    int s1, r1, s2, r2;
    cin >> s1 >> r1 >> s2 >> r2;
    map<string, int> mp1;
    map<int, string> mp2;
    vector<vector<pii>> adj(s1 + s2);
    int k = 0;
    for (int i = 0; i < r1 + r2; i++)
    {
        string a1, a2;
        int c;
        cin >> a1 >> a2 >> c;
        if (mp1.find(a1) == mp1.end())
        {
            mp1[a1] = k;
            mp2[k] = a1;
            k++;
        }
        if (mp1.find(a2) == mp1.end())
        {
            mp1[a2] = k;
            mp2[k] = a2;
            k++;
        }
        int u = mp1[a1], v = mp1[a2];
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    int p1, p2;
    cin >> p1;
    map<string, int> toll1, toll2;
    for (int i = 0; i < p1; i++)
    {
        string a;
        int c;
        cin >> a >> c;
        toll1[a] = c;
    }
    cin >> p2;
    for (int i = 0; i < p2; i++)
    {
        string a;
        int c;
        cin >> a >> c;
        toll2[a] = c;
    }
    string s, d;
    cin >> s >> d;
    vector<int> distance(s1 + s2, INF);
    vector<int> parent(s1 + s2, -1);
    dijkstra(adj, mp1[s], distance, parent);
    dijkstra(adj, mp1[d], distance, parent);
    int minCost = INF;
    for (pair<string, int> x1 : toll1)
    {
        for (pair<string, int> x2 : toll2)
        {
            if (minCost > distance[mp1[x1.first]] + x1.second + distance[mp1[x2.first]] + x2.second)
            {
                minCost = distance[mp1[x1.first]] + x1.second + distance[mp1[x2.first]] + x2.second;
                p1 = mp1[x1.first];
                p2 = mp1[x2.first];
            }
        }
    }
    cout << minCost << '\n';
    vector<int> path1, path2;
    getPath(parent, mp1[s], p1, path1);
    getPath(parent, mp1[d], p2, path2);
    for (int i = 0; i < path1.size(); i++)
    {
        cout << mp2[path1[i]] << "-> ";
    }
    for (int i = path2.size() - 1; i > 0; i--)
    {
        cout << mp2[path2[i]] << "-> ";
    }
    cout << mp2[path2[0]];
}