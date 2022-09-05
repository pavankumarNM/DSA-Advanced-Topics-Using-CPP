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
    vi a(n);
    rep(i, 0, n)
            cin >>
        a[i];
    int curr = 0, mx = 0;
    rep(i, 0, n)
    {
        curr += a[i];
        mx = max(mx, curr);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    cout << mx;
    return 0;
}