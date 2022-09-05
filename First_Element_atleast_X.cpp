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
        tree[st] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

// void update(int node, int st, int en, int idx, int val)
// {
//     if (st == en)
//     {
//         a[st] = val;
//         tree[node] = val;
//         return;
//     }
//     int mid = (st + en) / 2;
//     if (idx <= mid)
//     {
//         update(node * 2, st, mid, idx, val);
//     }
//     else
//     {
//         update(node * 2 + 1, mid + 1, en, idx, val);
//     }
//     tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
// }

// int query(int node, int st, int en, int l, int r)
// {

//     if (l < st || r > en)
//     {
//         return -M;
//     }
//     if (l <= st && r <= en)
//     {
//         return tree[node];
//     }
//     int mid = (st + en) / 2;
//     int q1 = query(2 * node, st, mid, l, r);
//     int q2 = query(2 * node + 1, mid + 1, en, l, r);
//     return max(q1, q2);
// }

int query(int node, int st, int end, int l, int r)
{
    if (r < st || end < l)
    {
        return -M;
    }
    if (l <= st && end <= r)
    {
        return tree[node];
    }
    int mid = (st + end) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);
    return max(q1, q2);
}

void update(int node, int st, int end, int idx, int val)
{
    if (st == end)
    {
        a[st] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + end) / 2;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, idx, val);
    }

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

signed main()
{
    int n, m;
    cin >> n >> m;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rep(j, 0, m)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx;
            cin >> idx;
            int val;
            cin >> val;
            update(1, 0, n - 1, idx, val);
        }
        if (type == 2)
        {
            int x;
            cin >> x;
            int low = 0, high = n - 1;
            int ans = n;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (query(1, 0, n - 1, low, mid) < x)
                {
                    int low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                    ans = min(ans, mid);
                }
            }
            if (ans == n)
            {
                cout << "-1" << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
    return 0;
}