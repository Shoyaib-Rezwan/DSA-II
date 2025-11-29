// you are given a weighted DAG. Find the shortest path distance from each vertex to each other along with the path
/*
input:
5 9
0 1 3
0 2 8
0 4 -4
1 3 1
1 4 7
2 1 4
3 2 -5
3 0 2
4 3 6
*/
#include <bits/stdc++.h>
#define INF INT32_MAX
using namespace std;
void getPath(int s, int u, vector<vector<int>> &predecessor, vector<int> &path)
{
    if (s == u)
    {
        path.push_back(u);
    }
    else
    {
        getPath(s, predecessor[s][u], predecessor, path);
        path.push_back(u);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> distance(n, vector<int>(n, INF)), predecessor(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        distance[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        distance[u][v] = w;
        predecessor[u][v] = u;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    predecessor[i][j] = predecessor[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (distance[i][j] != INF)
            {
                cout << "(" << i << ", " << j << "): " << distance[i][j] << ": ";
                vector<int> path;
                getPath(i, j, predecessor, path);
                for (int i = 0; i < path.size() - 1; i++)
                {
                    cout << path[i] << "->";
                }
                cout << path[path.size() - 1] << "\n";
            }
            else
            {
                cout << "(" << i << ", " << j << "): " << "INF" << '\n';
            }
        }
    }
}