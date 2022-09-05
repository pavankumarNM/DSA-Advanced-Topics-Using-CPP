#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<vi> multiply(vector<vi> &a, vector<vi> &b)
{
    int n = a.size();
    vector<vi> ans(n, vi(n, 0));
    rep(i, 0, n)
    {
        rep(j, 0, n)
            rep(k, 0, n)
                ans[i][j] += a[i][k] * b[k][j];
    }
    return ans;
}

vector<vi> MatrixMultiplication(vector<vi> &a, int n)
{
    if (n == 0)
    {
        int sz = a.size();
        vector<vi> ans(n, vi(n, 0));
        rep(i, 0, n)
        {
            ans[i][i] = 1;
        }
        return ans;
    }
    if (n == 1)
    {
        return a;
    }
    vector<vi> temp = MatrixMultiplication(a, n / 2);
    vector<vi> ans = multiply(temp, temp);
    if (n & 1)
    {
        return multiply(ans, a);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(2, 0));
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;

    vector<vi> ans = MatrixMultiplication(a, n);
    rep(i, 0, n)
    {
        rep(j, 0, n)
                cout
            << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

// don't know what the f****g error is shit this