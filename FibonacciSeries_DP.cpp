#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
// int dp[N];
// for (int i = 0; i < N; i++)
// {
//     dp[i] = -1;
// }
// int fib(int n)              // top to down (memoization)
// {
//     if (n == 0 || n == 1 )
//     {
//         return 0;
//     }

//     if (n == 2)
//     {
//         return 1;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     dp[n] = fib(n - 1) + fib(n - 2);
//     return dp[n];
// }

// int fib(int n)                   // bottom to up
// {
//     vector<int> temp(n + 1);
//     temp[0] = 0;

//     temp[1] = 0;
//     temp[2] = 1;
//     for (int i = 3; i <= n; i++)
//     {
//         temp[i] = temp[i - 1] + temp[i - 2];
//     }
//     return temp[n];
// }

int main()
{
    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}