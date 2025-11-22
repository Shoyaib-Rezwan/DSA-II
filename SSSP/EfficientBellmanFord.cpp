/*

You are given a weighted DAG....

Input:
5 5 0
1 2 5
0 1 -1
0 2 5
1 3 6
2 4 -2

Output=>
0: 0
1: -1
2: 4
3: 5
4: 2

Input:(Cormen 22-2)
6 10 1
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
3 5 1
4 5 -2

Output=>
0: INF
1: 0
2: 2
3: 6
4: 5
5: 3

*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT_MAX
using namespace std;
void toposort(vector<vector<pii>> &adj, int u, stack<int> &stk, vector<bool> &visited)
{
    visited[u] = true;
    for (pii x : adj[u])
    {
        int v = x.first;
        if (!visited[v])
        {
            toposort(adj, v, stk, visited);
        }
    }
    stk.push(u);
}
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
    vector<int> distance(n, INF);
    distance[s] = 0;
    stack<int> stk;
    vector<bool> visited(n, false);
    toposort(adj, s, stk, visited);
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        for (pii x : adj[u])
        {
            int v = x.first, w = x.second;
            if (distance[u] != INF && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
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