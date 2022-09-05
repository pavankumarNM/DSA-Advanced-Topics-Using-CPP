#include <iostream>
#include <climits>
using namespace std;
int main()
{ // ans came but after a long blood bath     fuck u tony
    int n;
    cin >> n;
    int a[n];
    a[n] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    int ans = 0;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (mx < a[i] && a[i] > a[i + 1])
        {
            ans++;
        }
        mx = max(mx, a[i]);
    }
    cout << "total number of record dates " << ans;

    return 0;
}