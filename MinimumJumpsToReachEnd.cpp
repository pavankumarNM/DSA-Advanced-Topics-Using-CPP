#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e9;
int main()
{
    int n; // I don't know what the fucking error-
    cin >> n;
    vi arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    vi jumps(n, N);
    if (arr[0] == 0)
    {
        cout << "Infinity";
        return 0;
    }
    jumps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + arr[j]))
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    cout << jumps[n - 1];

    return 0;
}