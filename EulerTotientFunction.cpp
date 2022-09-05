#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e5 + 2;
int totient[N];
int main()
{
    int n;
    cin >> n;
    rep(i, 0, N)
    {
        totient[i] = i;
    }
    for (int i = 2; i < N; i++)
    {
        if (totient[i] == i)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                totient[j] *= (i - 1);
                totient[j] /= i;
            }
            totient[i] = i - 1;
        }
    }
    rep(k, 2, n)
    {
        cout << totient[k] << " ";
    }
    return 0;
}