#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
void BFS(vector<vector<int>> &adj, vector<int> &distance, int u)
{
    int n = adj.size();
    vector<int> visited(n, false);
    queue<int> q;
    q.push(u);
    distance[u] = 0;
    visited[u] = true;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                distance[v] = distance[u] + 1;
                visited[v] = true;
            }
        }
    }
}
int main()
{
    int n, m, q, u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    cin >> q;
    vector<pii> pairs;
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v;
        pairs.push_back({u - 1, v - 1});
    }
    vector<int> distance(n);
    BFS(adj, distance, 0);
    BFS(adj, distance, 1);
    int minDist = INT32_MAX;
    pii minPair = {-1, -1};
    for (pii x : pairs)
    {
        if(distance[x.first]+distance[x.second]+1<minDist){
            minDist = distance[x.first] + distance[x.second]+1;
            minPair = x;
        }
    }
    cout << minPair.first+1 << ' ' << minPair.second+1 << '\n';
    cout << minDist;
}