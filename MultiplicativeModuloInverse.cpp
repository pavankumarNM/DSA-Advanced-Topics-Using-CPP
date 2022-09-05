#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

struct triplet
{
    int x, y, gcd;
};

triplet ExtendedEulids(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallans = ExtendedEulids(b, a % b);
    triplet ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a / b) * smallans.y;
    return ans;
}

int MultiplicativeModuloInverse(int a, int m)
{
    triplet ans;
    ans = ExtendedEulids(a, m);
    return ans.x;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << MultiplicativeModuloInverse(a, b);

    return 0;
}