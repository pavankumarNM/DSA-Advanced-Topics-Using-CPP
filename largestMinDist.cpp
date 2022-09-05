#include <bits/stdc++.h>
using namespace std;

bool isFesable(int arr[], int mid, int k, int n)
{
    int pos = arr[0];
    int ele = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            ele++;
            if (ele == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1;
    int right = arr[n - 1];

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFesable(arr, mid, k, n))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 8, 4, 9};
    int k = 3;
    int n = 5;
    cout << largestMinDist(arr, n, k);
    return 0;
}