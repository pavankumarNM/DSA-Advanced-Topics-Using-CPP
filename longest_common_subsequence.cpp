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

// int lcs(string &s1, string &s2, int n, int m)                   // memoization
// {
//     if (n == 0 || m == 0)
//     {
//         return 0;
//     }
//     if (dp[n][m] != -1)
//     {
//         return dp[n][m];
//     }

//     if (s1[n - 1] == s2[m - 1])
//     {
//         dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
//     }
//     else
//     {
//         dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
//     }
//     return dp[n][m];
// }

// int lcs(string &s1,string &s2,int n,int m)                      // normal code
// {
//     if (n == 0 || m == 0)
//     {
//         return 0;
//     }
//     if (s1[n-1] == s2[m-1])
//     {
//         return 1+lcs(s1,s2,n-1,m-1);
//     }
//     else
//     {
//         return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
//     }

// }

int main()
{
    // rep(i, 0, N)                                            //memoization(top down)
    // {
    //     rep(j, 0, N)
    //         dp[i][j] = -1;
    // }
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    // cout << lcs(s1, s2, n, m);
    //  vvi dp(n+1,vi(m+1,-1));                                // tabulation (bottom up)
    //  rep(i,0,n+1)
    //  {
    //      rep(j,0,m+1)
    //      {
    //          if (i ==0 || j==0)
    //          {
    //              dp[i][j]=0;
    //              continue;
    //          }
    //          if (s1[i-1] == s2[j-1])
    //          {
    //              dp[i][j]=1+dp[i-1][j-1];
    //          }
    //          else
    //          {
    //              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //          }
    //      }
    //  }
    //  cout<<dp[n][m];
    return 0;
}