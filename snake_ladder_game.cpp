#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ladder, moves = 0, snake;
    map<int, int> lad;
    map<int, int> snak;
    cin >> ladder;
    for (int i = 0; i < ladder; i++)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }

    cin >> snake;
    for (int i = 0; i < snake; i++)
    {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }
    vector<int> visited(101, false);

    queue<int> q;
    q.push(1);
    visited[1] = true;
    bool found = false;
    while (!q.empty() && !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                if (t + die == 100)
                {
                    found = true;
                }
                if (t + die <= 100 && lad[t + die] && !visited[lad[t + die]])
                {
                    if (t + die == 100)
                    {
                        found = true;
                    }

                    visited[lad[t + die]] = true;
                    q.push(lad[t + die]);
                }
                else if (t + die <= 100 && snak[t + die] && !visited[snak[t + die]])
                {
                    if (t + die == 100)
                    {
                        found = true;
                    }

                    visited[snak[t + die]] = true;
                    q.push(snak[t + die]);
                }
                else if (t + die <= 100 && !visited[t + die] && !lad[t + die] && !snak[t + die])
                {
                    visited[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }
    if (found)
    {
        cout << moves;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}