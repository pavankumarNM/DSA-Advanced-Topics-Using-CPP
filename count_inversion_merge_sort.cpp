#include <iostream>
using namespace std;
long long merge(int arr[], int l, int r, int pivot)
{
    long long inv = 0;
    int n1 = pivot - l + 1;
    int n2 = r - pivot;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        b[j] = arr[pivot + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            inv += n1 - i;
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }

    return inv;
}
long long mergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    if (l < r)
    {
        int pi = (l + r) / 2;
        inv += mergeSort(arr, l, pi);
        inv += mergeSort(arr, pi + 1, r);
        inv += merge(arr, l, r, pi);
    }
    return inv;
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << mergeSort(arr, 0, n - 1);

    return 0;
}