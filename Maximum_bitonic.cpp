#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{
    int n = 8;

    vi a = {1, 11, 2, 10, 4, 5, 2, 1};
    vi forward(n, 1);
    vi backward(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                forward[i] = max(forward[i], 1 + forward[j]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j])
            {
                backward[i] = max(backward[i], 1 + backward[j]);
            }
        }
    }
    int ans = 0;
    rep(i, 0, n)
    {
        ans = max(ans, forward[i] + backward[i] - 1);
    }
    cout << ans;
    return 0;
}