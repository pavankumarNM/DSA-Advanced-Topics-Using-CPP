#include <iostream>
#include <cmath>
using namespace std;
int main()
{ // got it       :)
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cur = 2;
    int ans = 2;
    int j = 1;
    int pd = a[1] - a[0];
    while (j < n)
    {
        if (a[j + 1] - a[j] == pd)
        {
            cur++;
        }
        else
        {
            pd = a[j] - a[j - 1];
            cur = 2;
        }
        ans = max(ans, cur);
        j++;
    }
    cout << ans << endl;

    return 0;
}