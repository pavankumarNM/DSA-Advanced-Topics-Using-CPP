#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>> pq;

int MinSizeOfKSum(int arr[], int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int sum = 0;
    int c = 0;
    while (pq.size())
    {
        sum += pq.top();
        pq.pop();
        c++;
        if (sum >= k)
        {
            break;
        }
    }
    if (sum < k)
    {
        return -1;
    }
    return c;
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

    cout << MinSizeOfKSum(arr, k, n);

    return 0;
}