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

vector<long long> power(N);

int p = 31;
int32_t main()
{
    string s = "na", t = "apnacollegena";

    int S = s.size();
    int T = t.size();
    power[0] = 1;
    for (int i = 0; i < N; i++)
    {
        power[i] = (power[i - 1] * p) % M;
    }
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % M;
    }
    long long h_s = 0;
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % M;
    }
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_hash = (h[i + S] - h[i] + M) % M;
        if (cur_hash == (h_s * power[i]) % M)
        {
            cout << "found at " << i << " \n";
        }
    }

    return 0;
}