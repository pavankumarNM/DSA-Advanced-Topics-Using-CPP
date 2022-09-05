#include <bits/stdc++.h>
using namespace std;

bool ispossible(int arr[], int n, int m, int min)
{
    int studentsReq = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return -1;
        }
        if (sum + arr[i] > min)
        {
            studentsReq++;
            sum = arr[i];
        }
        if (studentsReq > m)
        {
            return false;
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int allocateMinimumResources(int arr[], int n, int m)
{
    int sum = 0;
    if (n < m)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int start = 0;
    int end = sum;
    int res = INT_MAX;
    while (start < end)
    {

        int mid = (start + end) / 2;

        return 0;
        if (ispossible(arr, n, m, mid))
        {
            res = min(res, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << allocateMinimumResources(arr, n, m);
    return 0;
}