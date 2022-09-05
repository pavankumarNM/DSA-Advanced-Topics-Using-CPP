#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int num)
{
    int sum = 1;
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == num / i)
            {
                sum += i;
            }
            else
            {
                sum += i + num / i;
            }
        }
    }
    if (sum == num && num != 1)
    {
        return true;
    }
    return false;
}

int MaxPerfectDigit(int arr[], int n, int k)
{
    if (n < k)
    {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int res = sum;
    for (int j = k; j < n; j++)
    {
        sum += arr[j] - arr[j - k];
        res = max(res, sum);
    }
    return res;
}

int MaxSubPerfect(int arr[], int n, int k)
{

    for (int i = 0; i < n; i++)
    {

        if (isPerfect(arr[i]))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }

    return MaxPerfectDigit(arr, n, k);
}

int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int n = 8;
    int k = 4;
    cout << MaxSubPerfect(arr, n, k);
    return 0;
}