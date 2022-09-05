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
    int n;
    cin >> n;
    vi dp(n);
    dp[0] = 1;
    int c2(0), c3(0), c5(0);
    rep(i, 1, n)
    {
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
        if (dp[i] == (2 * dp[c2]))
        {
            c2++;
        }
        if (dp[i] == (3 * dp[c3]))
        {
            c3++;
        }
        if (dp[i] == (5 * dp[c5]))
        {
            c5++;
        }
    }
    cout << dp[n - 1];
    return 0;
}