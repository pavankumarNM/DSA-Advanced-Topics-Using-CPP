#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
// const int N=1e3+2;                                     // memoization
// int dp[N];

// int lfs(vector<int> &a,int n){
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     dp[n]=1;
//     rep(i,0,n){
//         if (a[i]<a[n])
//         {
//             dp[n]=max(dp[n],1+lfs(a,i));
//         }

//     }
//     return dp[n];
// }

int main()
{
    // rep(i,0,N){                                          // memoization
    //     dp[i]=-1;
    // }
    // int n;
    // cin>>n;
    // vi a(n);
    // rep(j,0,n){
    //     cin>>a[j];
    // }
    // cout<<lfs(a,n-1);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    vi a(n);
    vi dp(n, 1);
    rep(i, 1, n)
    {
        rep(j, 0, i) if (arr[j] < arr[i])
        {
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(dp[i], ans);
    }

    cout << ans;
    return 0;
}