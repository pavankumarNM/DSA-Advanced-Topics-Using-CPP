#include <bits/stdc++.h>
using namespace std;
int searchSortedRotedArr(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] >= key)
    {
        if (arr[left] <= key && key <= arr[mid])
        {
            return searchSortedRotedArr(arr, key, left, mid - 1);
        }
        return searchSortedRotedArr(arr, key, mid + 1, right);
    }
    if (arr[mid] <= key)
    {
        if (arr[mid] <= key && key <= arr[right])
        {
            return searchSortedRotedArr(arr, key, mid + 1, right);
        }
        return searchSortedRotedArr(arr, key, left, mid - 1);
    }
}
int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int n = 8;
    int key = 1;
    cout << searchSortedRotedArr(arr, key, 0, n - 1);

    return 0;
}