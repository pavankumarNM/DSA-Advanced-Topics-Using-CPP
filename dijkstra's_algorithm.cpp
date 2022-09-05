#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    const int INF = 1e9 + 2;
    vector<int> dist(n + 1, INF);
    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    int src;
    cin >> src;
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : g[x.second])
        {
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (dist[i] < INF)
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}