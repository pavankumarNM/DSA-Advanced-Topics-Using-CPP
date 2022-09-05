#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n]; // adding of subarray
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = i; j < n; j++)
        {
            cur += a[j];
            cout << cur << endl;
        }
    }

    return 0;
}