#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> col;
vector<bool> visited;
bool biparity = true;
void color(int u, int curr)
{
    if (col[u] != -1 && col[u] != curr)
    {
        biparity = false;
        return;
    }
    col[u] = curr;
    if (visited[u])
    {
        return;
    }
    visited[u] = 1;
    for (auto i : adj[u])
    {
        color(i, curr xor 1);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    col = vector<int>(n, -1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            color(i, 0);
        }
    }

    if (biparity)
    {
        cout << " Graph is Biparity";
    }
    else
    {
        cout << "Graph is not Biparity";
    }

    return 0;
}