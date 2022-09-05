#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e3 + 2;
int dp[N][N];
int coinchange(vector<int> &a, int n, int x)
{
    if (n <= 0)
    {
        return 0;
    }
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    dp[n][x] = coinchange(a, n, x - a[n - 1]) + coinchange(a, n, x);
    return dp[n][x];
}
int main()
{

    rep(i, 0, N)
        rep(j, 0, N)
            dp[i][j] = -1;

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << x;
    cout << coinchange(a, n, x) << endl;

    return 0;
}