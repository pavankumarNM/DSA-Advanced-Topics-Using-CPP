#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5 + 2;
int cost = 0;
const int INF = 1e9;
vector<vector<int>> g[N];
vector<bool> visited(N);
vector<int> dist(N);
vector<int> parent(N);

void primsalgo(int src)
{
    for (int i = 1; i < n; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    set<vector<int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto x = *(s.begin());
        visited[x[1]] = true;
        s.erase(x);
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << "\n";
        cost += w;
        for (auto it : g[x[1]])
        {
            if (visited[it[0]])
            {
                continue;
            }
            if (dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}
int main()
{

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsalgo(0);
    cout << cost;
    return 0;
}