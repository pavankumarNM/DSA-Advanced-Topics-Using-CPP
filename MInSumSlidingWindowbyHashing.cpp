#include <bits/stdc++.h>
using namespace std;

int getMinSum(int arr[], int k, int n)
{
    int ans = INT_MAX;
    int curSum = 0;
    for (int i = 0; i < k; i++)
    {
        curSum += arr[i];
    }
    ans = min(curSum, ans);
    for (int j = k; j < n - k + 1; j++)
    {
        curSum = curSum - arr[j] + arr[j + 1];
        ans = min(curSum, ans);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getMinSum(arr, k, n);

    return 0;
}