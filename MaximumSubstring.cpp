#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "pwepepe";
    vector<int> dist(256, -1);
    int maxlen = 0, start = -1,
        for (int i = 0; i < s.size(); i++)
    {
        if (dist[s[i]] > start)
        {
            start = dist[s[i]];
        }
        dist[s[i]] = i;
        maxlen = max(maxlen, i - start);
    }
    cout << maxlen;

    return 0;
}