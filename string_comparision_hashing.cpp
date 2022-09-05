#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e5 + 2, M = 1e9 + 7;
int p = 31;
vector<int> power(N);
long long calculate_hash(string s)
{
    long long hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + ((s[i] - 'a' + 1) * power[i]) % M;
    }
    return hash;
}
int main()
{

    power[0] = 1;
    for (int i = 1; i < N; i++)
    {
        power[i] = (power[i - 1] * p) % M;
    }

    vector<string> strings = {"aa", "ab", "b", "cc", "aa"};
    int n = strings.size();
    vector<long long> hashing;
    for (auto w : strings)
    {
        hashing.push_back(calculate_hash(w));
    }
    sort(hashing.begin(), hashing.end());
    int distinct = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || hashing[i - 1] != hashing[i])
        {
            distinct++;
        }
    }
    cout << distinct;

    return 0;
}