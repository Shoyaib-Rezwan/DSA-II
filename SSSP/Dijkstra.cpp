/*
You are given a weightd DAG along with a source. Find the shortest path distance of each vertes from that source. All edges are of non-negative weight

Input:
5 6 0
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3

Output=>
0: 0
1: 3
2: 1
3: 4
4: 7

Input:(Cormen 22-3)
5 10 0
0 1 10
0 4 5
1 2 1
1 4 2
2 3 4
3 0 7
3 2 6
4 1 3
1 2 9
4 3 2

Output=>
0: 0
1: 8
2: 9
3: 7
4: 5

*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT32_MAX
using namespace std;
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distance(n, INF);
    distance[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int dist_u = pq.top().first, u = pq.top().second;
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
            }
        }
    }
    for (int u = 0; u < n; u++)
    {
        if (distance[u] != INF)
            cout << u << ": " << distance[u] << '\n';
        else
            cout << u << ": INF\n";
    }
}