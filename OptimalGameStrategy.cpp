#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
int dp[100][100];
vi a;

int solve(int i, int j)
{
    if (i == j)
    {
        return a[i];
    }
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int l = a[i] + min(solve(i + 2, j), solve(i, j - 1));
    // A[i]   rem = a[i+1].....a[j]
    int r = a[j] + min(solve(i + 1, j - 1), solve(i, j - 2));
    // A[j] rem =a[i]....a[j-1]
    dp[i][j] = max(r, l);
    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;
    a = vi(n);
    memset(dp, -1, sizeof(dp));
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << solve(0, n - 1);

    return 0;
}