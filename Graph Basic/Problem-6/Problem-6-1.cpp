#include <bits/stdc++.h>
using namespace std;
//1-> No color
//2-> Red
//3-> Green
void DFS(vector<vector<int>> &adj, int u, vector<int>&color, bool &isBipartite){
    for(int v:adj[u]){
        if(color[v]==1){
            color[v] = (color[u] == 2) ? 3 : 2;
            DFS(adj, v, color, isBipartite);
        }
        else if(color[v]==color[u]){
            isBipartite = false;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, 1);
    bool isBipartite = true;
    for (int u = 0; u < n;u++){
        if(color[u]==1){
            color[u] = 2;
            DFS(adj, u, color, isBipartite);
            if(!isBipartite){
                cout << "Not Bipartite";
                return 1;
            }
        }
    }
    cout << "Bipartite";
}