#include <bits/stdc++.h>
using namespace std;

int MaxSumSubArr(int arr[], int n, int k, int x)
{
    int ans = INT_MIN, sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < x)
    {
        ans = sum;
    }

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - 1];
        sum += arr[i];
        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int n = 6;
    int k = 3;
    int x = 20;
    cout << MaxSumSubArr(arr, n, k, x);
    return 0;
}