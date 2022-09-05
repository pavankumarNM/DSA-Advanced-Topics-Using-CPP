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
    int len = sqrtl(n) + 1;
    vi b(len);
    rep(j, 0, n)
    {
        b[j / len] += a[j];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int sum = 0;
        for (int k = l; k <= r;)
        {
            if (k % len == 0 && k + len - 1 <= r)
            {
                sum += b[k / len];
                k += len;
            }
            else
            {
                sum += a[k];
                k++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}