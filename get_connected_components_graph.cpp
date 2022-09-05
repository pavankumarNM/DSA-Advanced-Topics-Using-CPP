#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> components;
int getcomponents(int idx)
{
    if (visited[idx])
    {
        return 0;
    }
    visited[idx] = true;
    int ans = 1;
    for (auto i : adj[idx])
    {
        if (!visited[i])
        {
            ans += getcomponents(i);
            visited[i] = true;
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);

    visited = vector<bool>(n, 0);

    for (int i = 0; i < m; i++)
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
            components.push_back(getcomponents(i));
        }
    }
    for (auto i : components)
    {
        cout << i << " ";
    }

    return 0;
}