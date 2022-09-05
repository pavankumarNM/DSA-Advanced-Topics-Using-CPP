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
int a[N], tree[4 * N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int st, int en, int idx)
{
    if (st == en)
    {
        if (a[st] == 0)
        {
            a[st] = 1;
            tree[node] = 1;
        }
        else
        {
            a[st] = 0;
            tree[node] = 0;
        }
        return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, idx);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int st, int en, int k)
{
    if (st == en)
    {
        return st;
    }
    int mid = (st + en) / 2;
    if (k < tree[2 * node])
    {
        return query(2 * node, st, mid, k);
    }
    else
    {
        return query(2 * node + 1, mid + 1, en, k - tree[2 * node]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    rep(i, 0, m)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx;
            cin >> idx;
            update(1, 0, n - 1, idx);
        }
        else
        {
            int k;
            cin >> k;
            int ans = query(1, 0, n - 1, k);
            cout << ans << endl;
        }
    }
    return 0;
}