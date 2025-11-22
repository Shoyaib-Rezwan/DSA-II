/*

Input:
1st line is V E s (vertex, edge number, source)
next E lines contains directed edges with weights: u v w

Output:
output minimum distance from the source to every other nodes

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

Input:
5 8 0
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

Output=>
0: 0
1: -1
2: 2
3: -2
4: 1

Input:(Cormen: 22-1)
5 10 0
0 1 6
0 4 7
1 2 5
1 3 -4
1 4 8
2 1 -2
3 0 2
4 2 -3
3 2 7
4 3 9

Output=>
0: 0
1: 2
2: 4
3: -2
4: 7

Input:
5 7 4
0 1 5
1 2 3
2 3 -6
3 2 7
3 1 3
3 0 -3
4 0 10

Output=>
Negative Weight Cycle Exists!!!

*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT_MAX
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
    vector<int> distance(n, INF);
    distance[s] = 0;
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
    bool negCycle = false;
    for (int u = 0; u < n; u++)
    {
        for (pii x : adj[u])
        {
            int v = x.first, w = x.second;
            if (distance[u] != INF && distance[v] > distance[u] + w)
            {
                negCycle = true;
            }
        }
    }
    if (negCycle)
    {
        cout << "Negative Weight Cycle Exists!!!";
    }
    else
    {
        for (int u = 0; u < n; u++)
        {
            cout << u << ": " << distance[u] << '\n';
        }
    }
}