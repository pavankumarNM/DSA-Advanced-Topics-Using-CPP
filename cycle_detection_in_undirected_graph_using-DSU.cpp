#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector<int> parent(N);
vector<int> sz(N);

void make_sets(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        make_sets(i);
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    bool cycle = false;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);

        if (x == y)
        {
            cycle = true;
        }
        else
        {
            union_sets(u, v);
        }
    }
    if (cycle)
    {
        cout << " cycle is present ";
    }
    else
    {
        cout << "cycle is not present";
    }

    return 0;
}