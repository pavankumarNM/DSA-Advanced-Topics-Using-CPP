#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

void freqByHashing(int arr[], int n)
{
    unordered_map<int, int> freq;
    rep(i, 0, n)
    {
        freq[arr[i]]++;
    }

    unordered_map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    freqByHashing(arr, n);

    return 0;
}