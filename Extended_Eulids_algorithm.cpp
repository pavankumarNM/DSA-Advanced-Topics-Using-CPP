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

triplet ExtendedEulid(int a, int b)
{

    if (b == 0)
    {
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallans = ExtendedEulid(b, a % b);
    triplet ans;
    ans.x = smallans.y;
    ans.gcd = smallans.gcd;
    ans.y = smallans.x - (a % b) * smallans.y;
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    triplet ans = ExtendedEulid(a, b);
    cout << ans.gcd << " " << ans.x << " " << ans.y << " " << endl;
    return 0;
}