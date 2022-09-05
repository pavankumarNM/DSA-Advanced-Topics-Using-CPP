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
vi bit;
int get_sum(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return idx;
}

void update(int n, int idx, int inc)
{
    while (idx <= n)
    {
        bit[idx] += inc;
        idx += idx & (-idx);
    }
}

int main()
{
    int n;
    cin >> n;
    vi a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    vi temp = a;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    bit = vi(n + 1);
    int inv = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        inv += get_sum(a[i] - 1);
        update(n, a[i], i);
    }
    cout << inv;

    return 0;
}