#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int dp[205][205][205];
int lcs(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if (i == 0 || j == 0 || k == 0)
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
    {
        return dp[i][j][k] = 1 + lcs(s1, s2, s3, i - 1, j - 1, k - 1);
    }
    else
    {
        int r = lcs(s1, s2, s3, i - 1, j, k);
        int p = lcs(s1, s2, s3, i, j - 1, k);
        int l = lcs(s1, s2, s3, i, j, k - 1);
        return dp[i][j][k] = max({r, p, l});
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << lcs(s1, s2, s3, s1.size(), s2.size(), s3.size());
    return 0;
}