#include <iostream>
using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int result = 0;
int uniquenum(int arr[], int n)
{
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getbit(arr[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
            result = setbit(result, i);
        }
    }
    return result;
}
int main()
{
    int arr[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 6};
    cout << uniquenum(arr, 11);
    return 0;
}