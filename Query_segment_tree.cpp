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
int a[N], tree[N * 4];

void build(int node, int st, int end)
{
    if (st == end)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st + end) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int st, int end, int l, int r)
{
    if (r < st || end < l)
    {
        return 0;
    }
    if (l <= st && end <= r)
    {
        return tree[node];
    }
    int mid = (st + end) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);
    return q1 + q2;
}

int main()
{
    int n;
    cin >> n;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    while (1)
    {
        int type;
        cin >> type;
        if (type == -1)
        {
            break;
        }
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans;
        }
    }

    return 0;
}