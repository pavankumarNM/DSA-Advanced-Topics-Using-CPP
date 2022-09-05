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
    int w;
    cin >> w;
    vector<int> wt = {3, 2, 4, 5, 1};
    vector<int> val = {4, 3, 5, 6, 1};
    vector<int> dp(w + 1, 0);

    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - wt[j] >= 0)
            {
                dp[i] = max(dp[i], val[j] + dp[i - wt[j]]);
            }
        }
    }
    cout << dp[w];

    return 0;
}