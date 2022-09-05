#include <bits/stdc++.h>
using namespace std;
bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
    stack[src] = true;
    if (!visited[src])
    {
        visited[src] = true;
        for (auto i : adj[src])
        {
            if (!visited[i] && iscycle(i, adj, visited, stack))
            {
                return true;
            }
            if (stack[i])
            {
                return true;
            }
        }
    }

    stack[src] = false;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    bool cycle = false;

    vector<int> stack(n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && iscycle(i, adj, visited, stack))
        {
            cycle = true;
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