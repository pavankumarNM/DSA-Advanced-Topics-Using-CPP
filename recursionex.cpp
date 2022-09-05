#include <iostream>
using namespace std;

int sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }

    return (arr[0] < arr[1] && sorted(arr + 1, n - 1));
}
void dec(int n)
{
    if (n == 0)
    {
        cout << 0;
        return;
    }
    cout << n << " ";
    dec(n - 1);
}
void inc(int n)
{
    if (n == 0)
    {
        cout << "0 ";
        return;
    }

    inc(n - 1);
    cout << n << " ";
}
int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i + 1, key);
}
int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int resarray = lastocc(arr, n, i + 1, key);
    if (resarray != -1)
    {
        return resarray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
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
    int key;
    cin >> key;

    // cout<<sorted(arr,n);
    // dec(n);
    // inc(n);
    cout << firstocc(arr, n, 0, key) << " ";
    cout << lastocc(arr, n, 0, key);
    return 0;
}