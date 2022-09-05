#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N];

vector<int> adjm(N);
void dfs(int node)
{
    vis[node] = 1;
    cout << node << " ";
    vector<int>::iterator it;
    for (it = adjm[node].begin(); it != adjm[node].end(); it++)
    {
        if (!vis[*it])
        {

            dfs(*it);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        vis[i] = false;
    }
    int x, y;
    for (int i = 0; i < m; i++)
    {

        cin >> x >> y;
        adjm[x].push_back(y);
        adjm[y].push_back(x);
    }
    dfs(1);

    return 0;
}