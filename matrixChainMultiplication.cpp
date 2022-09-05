#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 102;
const int MOD = 1e9 + 2;
int a[N];
int dp[N][N];

// int mmo(int i, int j)                      // memoization
// {
//     if (i == j)
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     dp[i][j] = MOD;
//     rep(k, i, j)
//     {
//         dp[i][j] = min(dp[i][j], mmo(i, k) + mmo(k + 1, j) + a[i - 1] * a[k] * a[j]);
//     }
//     return dp[i][j];
// }

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);

    rep(i, 0, n)
    {
        cin >> a[i];
    }
    cout << mmo(1, n - 1);
    return 0;
}