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
vector<int> bit;
int n;
int query(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

void update(int idx, int val)
{

    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int main()
{

    cin >> n;
    bit = vector<int>(n + 1);
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = query(r) - query(l - 1);
            cout << ans << " ";
        }
        else if (type == 2)
        {
            int idx, val;
            cin >> idx >> val;
            update(idx, -a[idx]);
            a[idx] = val;
            update(idx, val);
        }
    }

    return 0;
}