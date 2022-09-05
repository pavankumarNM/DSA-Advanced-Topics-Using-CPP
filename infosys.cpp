#include <iostream>
using namespace std;

int main()
{
    int n;
    int d;
    cin >> n;
    cin >> d;
    int arr[n];
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    int c = 0;
    for (int j = 1; j <= n; j++)
    {
        if (arr[j] - arr[j - 1] >= d)
        {
            c++;
        }
        else
        {
            c = 0;
        }
        ans = max(ans, c);
    }
    return ans;

    return 0;
}