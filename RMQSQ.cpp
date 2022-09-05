#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long
const int N = 1e5 + 2, M = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int len = (int)sqrtl(n) + 1;
    vi b(len, M);
    rep(j, 0, n)
    {
        b[j / len] = min(a[j], M);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int ans = M;
        for (int k = l; k <= r;)
        {
            if (k % len == 0 && k + len - 1 <= r)
            {
                ans = min(ans, b[k / len]);
                k += len;
            }
            else
            {
                ans = min(ans, a[k]);
                k++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}