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
int rootN;

struct Q
{
    int idx, l, r;
};
Q q[N];

bool compare(Q q1, Q q2)
{
    if (q1.l / rootN == q2.l / rootN)
    {
        return q1.r > q2.r;
    }

    return q1.l / rootN < q2.l / rootN;
}

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rootN = sqrtl(n);
    int queries;
    cin >> queries;
    rep(i, 0, queries)
    {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q, q + queries, compare);
    vi ans(queries);
    int cur_r = -1, cur_l = 0, l, r, cur_ans = 0;
    rep(j, 0, queries)
    {
        l = q[j].l;
        r = q[j].r;
        l--;
        r--;
        while (cur_r > r)
        {
            cur_ans -= a[cur_r];
            cur_r--;
        }
        while (cur_l > l)
        {
            cur_l--;
            cur_ans += a[cur_l];
        }
        while (cur_r < r)
        {
            cur_r++;
            cur_ans += a[cur_r];
        }
        while (cur_l < l)
        {
            cur_ans -= a[cur_l];
            cur_l++;
        }

        ans[q[j].idx] = cur_ans;
    }
    rep(k, 0, queries)
    {
        cout << ans[k] << " ";
    }
    return 0;
}