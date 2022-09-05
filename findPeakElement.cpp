#include <bits/stdc++.h>
using namespace std;

int findPeakElement(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
    {
        return mid;
    }
    else if (arr[mid - 1] > arr[mid] && mid > 0)
    {
        return findPeakElement(arr, low, mid - 1, n);
    }
    return findPeakElement(arr, mid + 1, high, n);
}

int main()
{
    int arr[] = {0, 8, 2, 3, 5, 7, 99, 11};
    int n = 7;
    cout << findPeakElement(arr, 0, n - 1, n);
    return 0;
}