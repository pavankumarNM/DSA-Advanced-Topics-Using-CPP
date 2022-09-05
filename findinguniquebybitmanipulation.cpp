#include <iostream>
using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int uniquenum(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int temp = xorsum;
    int pos = 0;
    int setpos = 0;
    while (setpos != 1)
    {
        setpos = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getbit(arr[i], pos - 1) != 0)
        {
            newxor = newxor ^ arr[i];
        }
    }
    cout << newxor << endl;
    cout << (newxor ^ temp) << endl;
}
int main()
{
    int n = 7;
    int arr[n] = {1, 2, 3, 4, 1, 2, 5};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    uniquenum(arr, n);

    return 0;
}