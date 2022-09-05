#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int e = 1, a = 0, ab = 0, abc = 0;
    rep(i, 0, n)
    {
        if (s[i] == 'a')
        {
            a += e;
        }
        else if (s[i] == 'b')
        {
            ab += a;
        }
        else if (s[i] == 'c')
        {
            abc += ab;
        }
        else if (s[i] == '?')
        {
            abc += abc * 3 + ab;
            ab = 3 * ab + a;
            a = 3 * e + a;
        }
    }
    cout << abc << endl;
    return 0;
}