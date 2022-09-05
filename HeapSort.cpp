#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int maxidx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[maxidx])
    {
        maxidx = l;
    }
    if (r < n && arr[r] > arr[maxidx])
    {
        maxidx = r;
    }
    if (maxidx != i)
    {
        swap(arr[i], arr[maxidx]);
        heapify(arr, n, maxidx);
    }
}

void HeapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {6, 5, 4, 3, 2, 1};
    HeapSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}