#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    int zc = 0, ans = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zc++;
        }
        while (zc > k)
        {
            if (a[j] == 0)
            {
                zc--;
            }
            i++;
        }

        ans = max(ans, j - i + 1);
    }

    cout << ans;
    return 0;
}